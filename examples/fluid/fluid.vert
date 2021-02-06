R"glsl(

#version 330 core

layout (location = 0) in vec2 position;
layout (location = 1) in vec4 color;

uniform vec4 wave_matrix;
uniform float start_time;
uniform vec2 resolution;

out vec4 out_wave_matrix;
out float out_start_time;
out vec2 out_resolution;
out vec4 out_color;

void main()
{
    gl_Position = vec4(position, 0.0, 1.0);
    out_wave_matrix = wave_matrix;
    out_start_time = start_time;
    out_resolution = resolution;
    out_color = color;
}


)glsl"
