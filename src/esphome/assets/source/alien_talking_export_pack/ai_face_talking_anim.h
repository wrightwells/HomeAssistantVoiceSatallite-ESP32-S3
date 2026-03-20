#pragma once
#include "lvgl.h"

LV_IMG_DECLARE(ai_face_talk_0);
LV_IMG_DECLARE(ai_face_talk_1);
LV_IMG_DECLARE(ai_face_talk_2);
LV_IMG_DECLARE(ai_face_talk_3);
LV_IMG_DECLARE(ai_face_talk_4);
LV_IMG_DECLARE(ai_face_talk_5);

static const lv_img_dsc_t * ai_face_talking_frames[] = {
    &ai_face_talk_0,
    &ai_face_talk_1,
    &ai_face_talk_2,
    &ai_face_talk_3,
    &ai_face_talk_4,
    &ai_face_talk_5,
};

#define AI_FACE_TALKING_FRAME_COUNT 6
