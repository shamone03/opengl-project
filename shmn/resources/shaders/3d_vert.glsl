﻿#version 460 core
layout (location = 0) in vec3 pos;
layout (location = 1) in vec3 color;
layout (location = 2) in vec2 textCoord;

out vec2 vertTextCoord;

void main() {
    gl_Position = vec4(pos, 1.0f);
    vertTextCoord = textCoord;
}
