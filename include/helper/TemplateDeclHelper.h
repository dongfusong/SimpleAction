/*
 * TemplateDeclHelper.h
 *
 *  Created on: 2014Äê11ÔÂ9ÈÕ
 *      Author: Thoughtworks
 */

////////////////////////////////////
//#define TYPENAME_ACTION
#define END_TYPENAME_ACTION(n) ,TYPENAME_ACTION(n)
#define DEFAULT_TEMPLATES(n) SIMPLE_REPEAT(TYPENAME_ACTION, END_TYPENAME_ACTION, n)

////////////////////////////////////
//#define ACTION(n)
#define END_ACTION(n) ,ACTION(n)
#define ACTIONS(n) SIMPLE_REPEAT(ACTION, END_ACTION, n)

////////////////////////////////////
//#define PUSHBACK(n)
#define PUSHBACKS(n) SIMPLE_REPEAT(PUSHBACK, PUSHBACK, n)

////////////////////////////////////
//#define ACTION_DECL(n)
#define ACTION_DECLS(n) SIMPLE_REPEAT(ACTION_DECL, ACTION_DECL, n)
////////////////////////////////////

//#define DECL_TEMPLATE(n)
#define END_DECL_TEMPLATE(n) ,DECL_TEMPLATE(n)
#define DECL_TEMPLATES(n) SIMPLE_REPEAT(DECL_TEMPLATE, END_DECL_TEMPLATE, n)


#define ACTION_PARTS(n) SIMPLE_REPEAT(ACTION, END_ACTION, n)
#define DUMMY(n) DummySchedAction
#define END_DUMMY(n) ,DummySchedAction
#define DUMMY_PARTS(n) SIMPLE_REPEAT(DUMMY, END_DUMMY, n)
#define PARTIAL_TEMPLATES(n, macroA, macroB) PARTIAL_TEMPLATES_##n(macroA, macroB)


