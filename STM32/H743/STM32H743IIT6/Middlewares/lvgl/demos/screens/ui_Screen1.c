// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.4
// LVGL version: 8.2.0
// Project name: SquareLine_Project

#include "../ui.h"

void ui_Screen1_screen_init(void)
{
    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Screen1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Screen1_Panel1 = lv_obj_create(ui_Screen1);
    lv_obj_set_width(ui_Screen1_Panel1, 304);
    lv_obj_set_height(ui_Screen1_Panel1, 193);
    lv_obj_set_x(ui_Screen1_Panel1, 311);
    lv_obj_set_y(ui_Screen1_Panel1, 124);
    lv_obj_set_align(ui_Screen1_Panel1, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Screen1_Panel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Screen1_Keyboard1 = lv_keyboard_create(ui_Screen1_Panel1);
    lv_obj_set_width(ui_Screen1_Keyboard1, 300);
    lv_obj_set_height(ui_Screen1_Keyboard1, 120);
    lv_obj_set_x(ui_Screen1_Keyboard1, 0);
    lv_obj_set_y(ui_Screen1_Keyboard1, 37);
    lv_obj_set_align(ui_Screen1_Keyboard1, LV_ALIGN_CENTER);

    ui_Screen1_TextArea1 = lv_textarea_create(ui_Screen1_Panel1);
    lv_obj_set_width(ui_Screen1_TextArea1, 100);
    lv_obj_set_height(ui_Screen1_TextArea1, 40);
    lv_obj_set_x(ui_Screen1_TextArea1, -60);
    lv_obj_set_y(ui_Screen1_TextArea1, -59);
    lv_obj_set_align(ui_Screen1_TextArea1, LV_ALIGN_CENTER);
    lv_textarea_set_placeholder_text(ui_Screen1_TextArea1, "Placeholder...");



    ui_Screen1_TextArea3 = lv_textarea_create(ui_Screen1_Panel1);
    lv_obj_set_width(ui_Screen1_TextArea3, 100);
    lv_obj_set_height(ui_Screen1_TextArea3, 40);
    lv_obj_set_x(ui_Screen1_TextArea3, 60);
    lv_obj_set_y(ui_Screen1_TextArea3, -59);
    lv_obj_set_align(ui_Screen1_TextArea3, LV_ALIGN_CENTER);
    lv_textarea_set_placeholder_text(ui_Screen1_TextArea3, "Placeholder...");



    ui_Screen1_Panel3 = lv_obj_create(ui_Screen1);
    lv_obj_set_width(ui_Screen1_Panel3, 251);
    lv_obj_set_height(ui_Screen1_Panel3, 37);
    lv_obj_set_x(ui_Screen1_Panel3, 335);
    lv_obj_set_y(ui_Screen1_Panel3, -122);
    lv_obj_set_align(ui_Screen1_Panel3, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Screen1_Panel3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Screen1_Slider2 = lv_slider_create(ui_Screen1_Panel3);
    lv_slider_set_value(ui_Screen1_Slider2, 10, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_Screen1_Slider2) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_Screen1_Slider2, 0,
                                                                                                    LV_ANIM_OFF);
    lv_obj_set_width(ui_Screen1_Slider2, 185);
    lv_obj_set_height(ui_Screen1_Slider2, 10);
    lv_obj_set_x(ui_Screen1_Slider2, -21);
    lv_obj_set_y(ui_Screen1_Slider2, -1);
    lv_obj_set_align(ui_Screen1_Slider2, LV_ALIGN_CENTER);


    ui_Screen1_Label2 = lv_label_create(ui_Screen1_Panel3);
    lv_obj_set_width(ui_Screen1_Label2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Screen1_Label2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Screen1_Label2, 100);
    lv_obj_set_y(ui_Screen1_Label2, -1);
    lv_obj_set_align(ui_Screen1_Label2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Screen1_Label2, "10%");

    ui_Screen1_Switch1 = lv_switch_create(ui_Screen1);
    lv_obj_set_width(ui_Screen1_Switch1, 50);
    lv_obj_set_height(ui_Screen1_Switch1, 25);
    lv_obj_set_x(ui_Screen1_Switch1, 52);
    lv_obj_set_y(ui_Screen1_Switch1, -90);
    lv_obj_set_align(ui_Screen1_Switch1, LV_ALIGN_CENTER);


    lv_obj_add_event_cb(ui_Screen1_TextArea1, ui_event_Screen1_TextArea1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Screen1_TextArea3, ui_event_Screen1_TextArea3, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Screen1_Slider2, ui_event_Screen1_Slider2, LV_EVENT_ALL, NULL);

}
