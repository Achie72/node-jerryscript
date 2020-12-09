#include "v8jerry_webassembly.hpp"
#include "v8jerry_utils.hpp"

namespace JerryWebAssembly {


static jerry_value_t webassembly_handler(
    const jerry_value_t func_value, /**< function object */
    const jerry_value_t this_val,   /**< this arg */
    const jerry_value_t args_p[],   /**< function arguments */
    const jerry_length_t args_cnt)  /**< number of function arguments */
{
    return jerry_create_undefined();
}

static jerry_value_t webassemly_compile_handler(
    const jerry_value_t func_value, /**< function object */
    const jerry_value_t this_val,   /**< this arg */
    const jerry_value_t args_p[],   /**< function arguments */
    const jerry_length_t args_cnt)  /**< number of function arguments */
{
    return jerry_create_undefined();
}

static jerry_value_t webassemly_validate_handler(
    const jerry_value_t func_value, /**< function object */
    const jerry_value_t this_val,   /**< this arg */
    const jerry_value_t args_p[],   /**< function arguments */
    const jerry_length_t args_cnt)  /**< number of function arguments */
{

   wasm_engine_t* engine = wasm_engine_new();
   wasm_store_t* store = wasm_store_new(engine);

    size_t byteLenght;
   wasm_byte_vec_t binary;
   wasm_byte_vec_new_uninitialized(&binary, byteLenght);

    bool result = false;
    //bool result =wasm_module_validate(store, binary);
    return jerry_create_boolean(result);
}

void Initialize() {
    JerryxHandlerRegisterGlobal((const jerry_char_t*)"WebAssembly",
                                    webassembly_handler);
    jerry_value_t global_obj_val = jerry_get_global_object();
    jerry_value_t name_val = jerry_create_string((const jerry_char_t*)"WebAssembly");
    jerry_value_t webassembly_val = jerry_get_property(global_obj_val, name_val);
    jerry_release_value(name_val);
    jerry_release_value(global_obj_val);

    jerry_value_t prototype_val = jerry_get_prototype(webassembly_val);
    jerry_release_value(webassembly_val);

    // Atomics.add
    JerryxHandlerRegister(
        (const jerry_char_t*)"compile", prototype_val, webassemly_compile_handler);
    // Atomics.load
    JerryxHandlerRegister(
        (const jerry_char_t*)"validate", prototype_val, webassemly_validate_handler);

    jerry_release_value(prototype_val);
    return;
    }
}
