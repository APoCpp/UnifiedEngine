R"glsl(

#version 330 core

out vec4 fragment_color;

in vec4 out_wave_matrix;
in float out_start_time;
in vec2 out_resolution;
in vec4 out_color;

// @note: a lot of magick numbers
float position_random(in vec2 position) {
    return fract(sin(dot(position.xy, vec2(12.9898, 78.233))) * 43758.5453123);
}

// @link: https://www.shadertoy.com/view/4dS3Wd
float position_noise(in vec2 position) {
    vec2
        i = floor(position),
        f = fract(position);

    float
        a = position_random(i),
        b = position_random(i + vec2(1.0, 0.0)),
        c = position_random(i + vec2(0.0, 1.0)),
        d = position_random(i + vec2(1.0, 1.0));

    vec2 u = f * f * (3.0 - 2.0 * f);

    return mix(a, b, u.x) + (c - a) * u.y * (1.0 - u.x) + (d - b) * u.x * u.y;
}

const int octaves_count = 4;

float position_fbm(in vec2 position) {
    float value = 0.0;

    mat2 rot = mat2(out_wave_matrix.x, out_wave_matrix.y, out_wave_matrix.z, out_wave_matrix.w);
    for (int i = 0; i < octaves_count; ++i) {
        value += 0.25 * position_noise(position);
        position = rot * position * 2.0 + vec2(-0.2, -0.7);
    }

    return value;
}

void main() {
    vec2 position = gl_FragCoord.xy / out_resolution.xy;

    vec2 q = vec2(position_fbm(position), position_fbm(position + vec2(1.0)));

    vec2 r = vec2(0.0);
    r.x = position_fbm(position + 1.0 * q + vec2(1.0, 1.0) + 0.085 * out_start_time);
    r.y = position_fbm(position + 1.0 * q + vec2(1.0, 1.0) + 0.085 * out_start_time);

    fragment_color = vec4(position_fbm(position + r) * vec3(out_color), 1.0);
}

)glsl"
