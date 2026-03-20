#pragma once
#include "lvgl.h"

LV_IMG_DECLARE(ai_face_quizzical_0);
LV_IMG_DECLARE(ai_face_quizzical_1);
LV_IMG_DECLARE(ai_face_quizzical_2);
LV_IMG_DECLARE(ai_face_quizzical_3);
LV_IMG_DECLARE(ai_face_quizzical_4);
LV_IMG_DECLARE(ai_face_quizzical_5);

static const lv_img_dsc_t * ai_face_quizzical_frames[] = {
    &ai_face_quizzical_0,
    &ai_face_quizzical_1,
    &ai_face_quizzical_2,
    &ai_face_quizzical_3,
    &ai_face_quizzical_4,
    &ai_face_quizzical_5,
};

#define AI_FACE_QUIZZICAL_FRAME_COUNT 6
