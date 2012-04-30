
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/require.h"
#include "kernel/object.h"
#include "kernel/debug.h"
#include "kernel/assert.h"
#include "kernel/array.h"
#include "kernel/memory.h"

#include "zend_operators.h"
#include "zend_exceptions.h"
#include "zend_interfaces.h"

/**
 * Phalcon_Model_Validator constructor
 *
 * @param Phalcon_Model_Base $record
 * @param string $field
 * @param string $value
 * @param array $options
 */
PHP_METHOD(Phalcon_Model_Validator, __construct){

	zval *a0 = NULL, *a1 = NULL, *a2 = NULL;
	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_property(phalcon_model_validator_class_entry, this_ptr, "_options", strlen("_options"), a0 TSRMLS_CC);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	zend_update_property(phalcon_model_validator_class_entry, this_ptr, "_messages", strlen("_messages"), a1 TSRMLS_CC);
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz|z", &v0, &v1, &v2, &v3) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v3) {
		PHALCON_INIT_VAR(a2);
		array_init(a2);
		PHALCON_CPY_WRT(v3, a2);
	}
	
	phalcon_update_property_zval(this_ptr, "_record", strlen("_record"), v0 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_fieldName", strlen("_fieldName"), v1 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_value", strlen("_value"), v2 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_options", strlen("_options"), v3 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Appends a message to the validator
 *
 * @param string $message
 * @param string $field
 * @param string $type
 */
PHP_METHOD(Phalcon_Model_Validator, appendMessage){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL, NULL, NULL }, *p2[] = { NULL, NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|zz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_STRING(v1, "", 1);
	} else {
		PHALCON_SEPARATE_PARAM(v1);
	}
	if (!v2) {
		PHALCON_INIT_VAR(v2);
		ZVAL_STRING(v2, "", 1);
	} else {
		PHALCON_SEPARATE_PARAM(v2);
	}
	
	if (PHALCON_COMPARE_STRING(v1, "")) {
		PHALCON_ALLOC_ZVAL_MM(t0);
		phalcon_read_property(&t0, this_ptr, "_fieldName", sizeof("_fieldName")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v1, t0);
	}
	if (PHALCON_COMPARE_STRING(v2, "")) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_INIT_VAR(p0[0]);
		ZVAL_STRING(p0[0], "Validator", 1);
		PHALCON_INIT_VAR(p0[1]);
		ZVAL_STRING(p0[1], "", 1);
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_FUNC_PARAMS_1(r1, "get_class", this_ptr, 0x02F);
		p0[2] = r1;
		PHALCON_CALL_FUNC_PARAMS(r0, "str_replace", 3, p0, 0x003);
		PHALCON_CPY_WRT(v2, r0);
	}
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, phalcon_model_message_class_entry);
	Z_ADDREF_P(v0);
	p2[0] = v0;
	Z_ADDREF_P(v1);
	p2[1] = v1;
	Z_ADDREF_P(v2);
	p2[2] = v2;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 3, p2, PHALCON_CALL_CHECK);
	Z_DELREF_P(p2[0]);
	Z_DELREF_P(p2[1]);
	Z_DELREF_P(p2[2]);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_messages", sizeof("_messages")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(i0);
	phalcon_array_append(t1, i0 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_messages", strlen("_messages"), t1 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns messages generated by the validator
 *
 * @return array
 */
PHP_METHOD(Phalcon_Model_Validator, getMessages){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_messages", sizeof("_messages")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Check whether option "required" has been passed as option
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Validator, isRequired){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(v0);
	ZVAL_BOOL(v0, 1);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_value", sizeof("_value")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_INIT_VAR(t1);
	ZVAL_STRING(t1, "", 1);
	PHALCON_INIT_VAR(r0);
	is_identical_function(r0, t1, t0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_value", sizeof("_value")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_INIT_VAR(t3);
	ZVAL_NULL(t3);
	PHALCON_INIT_VAR(r1);
	is_identical_function(r1, t3, t2 TSRMLS_CC);
	PHALCON_INIT_VAR(r2);
	ZVAL_BOOL(r2, zend_is_true(r0) || zend_is_true(r1));
	if (zend_is_true(r2)) {
		PHALCON_ALLOC_ZVAL_MM(t4);
		phalcon_read_property(&t4, this_ptr, "_options", sizeof("_options")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		eval_int = phalcon_array_isset_string(t4, "required", strlen("required")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(t5);
			phalcon_read_property(&t5, this_ptr, "_options", sizeof("_options")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r3);
			phalcon_array_fetch_string(&r3, t5, "required", strlen("required"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CPY_WRT(v0, r3);
		}
		PHALCON_RETURN_CHECK_CTOR(v0);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns all the options from the validator
 *
 * @return array
 */
PHP_METHOD(Phalcon_Model_Validator, getOptions){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_options", sizeof("_options")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Returns an option
 *
 * @paramstring $option
 * @returnmixed
 */
PHP_METHOD(Phalcon_Model_Validator, getOption){

	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_options", sizeof("_options")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v0);
	PHALCON_INIT_VAR(r1);
	ZVAL_BOOL(r1, eval_int);
	if (zend_is_true(r1)) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_options", sizeof("_options")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r2);
		phalcon_array_fetch(&r2, t1, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
		r0 = r2;
	} else {
		PHALCON_INIT_VAR(t2);
		ZVAL_STRING(t2, "", 1);
		r0 = t2;
	}
	PHALCON_RETURN_CHECK_CTOR(r0);
}

/**
 * Check whether a option has been defined in the validator options
 *
 * @paramstring $option
 * @returnboolean
 */
PHP_METHOD(Phalcon_Model_Validator, isSetOption){

	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_options", sizeof("_options")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v0);
	PHALCON_INIT_VAR(r1);
	ZVAL_BOOL(r1, eval_int);
	if (zend_is_true(r1)) {
		PHALCON_INIT_VAR(t1);
		ZVAL_BOOL(t1, 1);
		r0 = t1;
	} else {
		PHALCON_INIT_VAR(t2);
		ZVAL_BOOL(t2, 0);
		r0 = t2;
	}
	PHALCON_RETURN_CHECK_CTOR(r0);
}

/**
 * Returns the value of the validated field
 *
 * @returnmixed
 */
PHP_METHOD(Phalcon_Model_Validator, getValue){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_value", sizeof("_value")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Devuelve el nombre del campo validado
 *
 * @access protected
 * @return string
 */
PHP_METHOD(Phalcon_Model_Validator, getFieldName){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_fieldName", sizeof("_fieldName")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Returns Phalcon_Model_Base related record
 *
 * @return ActiveRecord
 */
PHP_METHOD(Phalcon_Model_Validator, getRecord){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_record", sizeof("_record")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * This method can be overridden to implement specific option validations for the validator
 *
 */
PHP_METHOD(Phalcon_Model_Validator, checkOptions){


	PHALCON_MM_GROW();
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}
