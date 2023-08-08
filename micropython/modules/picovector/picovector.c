#include "picovector.h"

STATIC MP_DEFINE_CONST_FUN_OBJ_KW(VECTOR_polygon_obj, 2, VECTOR_polygon);
STATIC MP_DEFINE_CONST_FUN_OBJ_KW(VECTOR_regular_polygon_obj, 6, VECTOR_regular_polygon);

// class
STATIC const mp_rom_map_elem_t VECTOR_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_polygon), MP_ROM_PTR(&VECTOR_polygon_obj) },
    { MP_ROM_QSTR(MP_QSTR_regular_polygon), MP_ROM_PTR(&VECTOR_regular_polygon_obj) },
};

STATIC MP_DEFINE_CONST_DICT(VECTOR_locals_dict, VECTOR_locals_dict_table);

#ifdef MP_DEFINE_CONST_OBJ_TYPE
MP_DEFINE_CONST_OBJ_TYPE(
    VECTOR_type,
    MP_QSTR_picovector,
    MP_TYPE_FLAG_NONE,
    make_new, VECTOR_make_new,
    locals_dict, (mp_obj_dict_t*)&VECTOR_locals_dict
);
#else
const mp_obj_type_t VECTOR_type = {
    { &mp_type_type },
    .name = MP_QSTR_picovector,
    .make_new = VECTOR_make_new,
    .locals_dict = (mp_obj_dict_t*)&VECTOR_locals_dict,
};
#endif

// module
STATIC const mp_map_elem_t VECTOR_globals_table[] = {
    { MP_OBJ_NEW_QSTR(MP_QSTR___name__), MP_OBJ_NEW_QSTR(MP_QSTR_picovector) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_PicoVector), (mp_obj_t)&VECTOR_type },
};

STATIC MP_DEFINE_CONST_DICT(mp_module_VECTOR_globals, VECTOR_globals_table);

const mp_obj_module_t VECTOR_user_cmodule = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t*)&mp_module_VECTOR_globals,
};

#if MICROPY_VERSION <= 70144
MP_REGISTER_MODULE(MP_QSTR_picovector, VECTOR_user_cmodule, MODULE_PICOVECTOR_ENABLED);
#else
MP_REGISTER_MODULE(MP_QSTR_picovector, VECTOR_user_cmodule);
#endif