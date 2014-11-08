/*
 * RepeatMacros.h
 *
 *  Created on: 2014Äê11ÔÂ8ÈÕ
 *      Author: Thoughtworks
 */

#ifndef REPEATMACROS_H_
#define REPEATMACROS_H_

#define SIMPLE_REPEAT(macro, endMacro, n) SIMPLE_REPEAT_##n(macro, endMacro)

#define SIMPLE_REPEAT_0(macro, EndMacro)
#define SIMPLE_REPEAT_1(macro, EndMacro) macro(1)
#define SIMPLE_REPEAT_2(macro, EndMacro) SIMPLE_REPEAT_1(macro, EndMacro) EndMacro(2)
#define SIMPLE_REPEAT_3(macro, EndMacro) SIMPLE_REPEAT_2(macro, EndMacro) EndMacro(3)
#define SIMPLE_REPEAT_4(macro, EndMacro) SIMPLE_REPEAT_3(macro, EndMacro) EndMacro(4)
#define SIMPLE_REPEAT_5(macro, EndMacro) SIMPLE_REPEAT_4(macro, EndMacro) EndMacro(5)
#define SIMPLE_REPEAT_6(macro, EndMacro) SIMPLE_REPEAT_5(macro, EndMacro) EndMacro(6)
#define SIMPLE_REPEAT_7(macro, EndMacro) SIMPLE_REPEAT_6(macro, EndMacro) EndMacro(7)
#define SIMPLE_REPEAT_8(macro, EndMacro) SIMPLE_REPEAT_7(macro, EndMacro) EndMacro(8)
#define SIMPLE_REPEAT_9(macro, EndMacro) SIMPLE_REPEAT_8(macro, EndMacro) EndMacro(9)
#define SIMPLE_REPEAT_10(macro, EndMacro) SIMPLE_REPEAT_9(macro, EndMacro) EndMacro(10)
#define SIMPLE_REPEAT_11(macro, EndMacro) SIMPLE_REPEAT_10(macro, EndMacro) EndMacro(11)
#define SIMPLE_REPEAT_12(macro, EndMacro) SIMPLE_REPEAT_11(macro, EndMacro) EndMacro(12)
#define SIMPLE_REPEAT_13(macro, EndMacro) SIMPLE_REPEAT_12(macro, EndMacro) EndMacro(13)
#define SIMPLE_REPEAT_14(macro, EndMacro) SIMPLE_REPEAT_13(macro, EndMacro) EndMacro(14)
#define SIMPLE_REPEAT_15(macro, EndMacro) SIMPLE_REPEAT_14(macro, EndMacro) EndMacro(15)


#define PARTIAL_TEMPLATES_1(macroA, macroB) macroA(1), macroB(14)
#define PARTIAL_TEMPLATES_2(macroA, macroB) macroA(2), macroB(13)
#define PARTIAL_TEMPLATES_3(macroA, macroB) macroA(3), macroB(12)
#define PARTIAL_TEMPLATES_4(macroA, macroB) macroA(4), macroB(11)
#define PARTIAL_TEMPLATES_5(macroA, macroB) macroA(5), macroB(10)
#define PARTIAL_TEMPLATES_6(macroA, macroB) macroA(6), macroB(9)
#define PARTIAL_TEMPLATES_7(macroA, macroB) macroA(7), macroB(8)
#define PARTIAL_TEMPLATES_8(macroA, macroB) macroA(8), macroB(7)
#define PARTIAL_TEMPLATES_9(macroA, macroB) macroA(9), macroB(6)
#define PARTIAL_TEMPLATES_10(macroA, macroB) macroA(10), macroB(5)
#define PARTIAL_TEMPLATES_11(macroA, macroB) macroA(11), macroB(4)
#define PARTIAL_TEMPLATES_12(macroA, macroB) macroA(12), macroB(3)
#define PARTIAL_TEMPLATES_13(macroA, macroB) macroA(13), macroB(2)
#define PARTIAL_TEMPLATES_14(macroA, macroB) macroA(14), macroB(1)


#endif /* REPEATMACROS_H_ */
