// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.4
// LVGL version: 8.2.0
// Project name: SquareLine_Project

#include "../ui.h"


// COMPONENT Screen1 Label1

lv_obj_t * ui_Screen1_Label1_create(lv_obj_t * comp_parent)
{

    lv_obj_t * cui_Screen1_Label1;
    cui_Screen1_Label1 = lv_label_create(comp_parent);
    lv_obj_set_width(cui_Screen1_Label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Screen1_Label1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(cui_Screen1_Label1, 100);
    lv_obj_set_y(cui_Screen1_Label1, -1);
    lv_obj_set_align(cui_Screen1_Label1, LV_ALIGN_CENTER);
    lv_label_set_text(cui_Screen1_Label1, "10%");

    lv_obj_t ** children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_SCREEN1_LABEL1_NUM);
    children[UI_COMP_SCREEN1_LABEL1_SCREEN1_LABEL1] = cui_Screen1_Label1;
    lv_obj_add_event_cb(cui_Screen1_Label1, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
    lv_obj_add_event_cb(cui_Screen1_Label1, del_component_child_event_cb, LV_EVENT_DELETE, children);
    ui_comp_Screen1_Label1_create_hook(cui_Screen1_Label1);
    return cui_Screen1_Label1;
}

