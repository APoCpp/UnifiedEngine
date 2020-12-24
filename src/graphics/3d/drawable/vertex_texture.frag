R"glsl(

#version 330 core

out vec4 fragment_color;

in vec2 out_texture_coord;

uniform sampler2D texture1;

void main()
{
    fragment_color = texture(texture1, out_texture_coord);
}

)glsl"
