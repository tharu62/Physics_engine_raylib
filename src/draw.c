#include "draw.h"

void draw (Camera2D* camera, rigid_body* body_list, int body_count) {

    for (int i = 0; i < body_count; ++i) {
        switch (body_list[i].shape)
        {
        case Circle:
            DrawCircleV(body_list[i].position, body_list[i].radius, body_list[i].color);
            break;

        case Box:
            vec p[4] = {
                body_list[i].transformed_vertices.array[0], // top-left
                body_list[i].transformed_vertices.array[1], // top-right
                body_list[i].transformed_vertices.array[2], // bottom-right
                body_list[i].transformed_vertices.array[3]  // bottom-left
            };
            for (int k = 0; k < 4; k++) {
                p[k].y = -p[k].y;
            }
            Color color = body_list[i].color;
            DrawLineV(p[0], p[1], color);
            DrawLineV(p[1], p[2], color);
            DrawLineV(p[2], p[3], color);
            DrawLineV(p[3], p[0], color);
            break;
        default:
            break;
        }
    }
    return;
}

void draw_with_sat_detection (Camera2D* camera, rigid_body* body_list, int body_count) {

    for (int i = 0; i < body_count; ++i) {
        switch (body_list[i].shape)
        {
        case Circle:
            DrawCircleV(body_list[i].position, body_list[i].radius, body_list[i].color);
            break;

        case Box:
            vec p[4] = {
                body_list[i].transformed_vertices.array[0], // top-left
                body_list[i].transformed_vertices.array[1], // top-right
                body_list[i].transformed_vertices.array[2], // bottom-right
                body_list[i].transformed_vertices.array[3]  // bottom-left
            };
            for (int k = 0; k < 4; k++) {
                p[k].y = -p[k].y;
            }
            Color color = body_list[i].color;
            float temp = 0.f;
            vec v = {0.f,0.f};
            for(int j=0; j<body_count; ++j){
                if(sat_vertices_intersection(&body_list[i].transformed_vertices, &body_list[j].transformed_vertices, &v, &temp) && i!=j){
                    color = RED;
                    break;
                }
            }
            DrawLineV(p[0], p[1], color);
            DrawLineV(p[1], p[2], color);
            DrawLineV(p[2], p[3], color);
            DrawLineV(p[3], p[0], color);
            break;
        default:
            break;
        }
    }
    return;
}