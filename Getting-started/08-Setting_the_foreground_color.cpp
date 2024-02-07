/**
 *  Easy Graphics Engine (https://xege.org)
 *  设置前景色
 *
 *  程序说明:
 *          前景色与背景色相对，是指图形元素的颜色，在 EGE 中，前景色主要影响线条、图形边框
 *      和文本的颜色，使用 setcolor() 进行设置。
 *          1. 初始化后，前景色默认为 #A8A8A8(浅灰色)。
 *          2. 调用 setcolor() 设置前景色后，会一直生效到下一次前景色改变为止。设置前景色只
 *      会影响后面绘制的图形，在设置之前已经绘制出的图形，其颜色不会改变，所以在绘制图形前，
 *      需要提前设置好前景色。
 *
 *  相关函数:
 *      setcolor():     设置前景色(影响线条、图形边框、文本)
 *      -- rectangle(): 绘制矩形边框
 *      -- line():      绘制直线
 *      -- circle():    绘制圆形边框
 *      -- xyprintf():  输出文本
 */

#include <graphics.h>
#include <stdio.h>

int main()
{
    // 初始化，窗口设置为 640x480 大小
    initgraph(640, 360, 0);

    //设置深色背景
    setbkcolor(EGERGB(0x30, 0x30, 0x30));

    //设置线条宽度
    setlinewidth(2.0f);

    // 使用默认前景色绘制一个矩形边框
    rectangle(20, 20, 280, 160);

    //设置蓝色前景色，并绘制一条直线
    setcolor(EGERGB(92, 167, 233));
    line(40, 320, 240, 120);

    //设置前景色为绿色，绘制一个圆
    setcolor(EGERGB(115, 201, 120));
    circle(500, 140, 100);

    //设置前景色为橙色，设置字体高度为32，文本背景透明并输出文本
    setcolor(EGERGB(235, 94, 67));
    setfont(32, 0, "");
    setbkmode(TRANSPARENT);
    xyprintf(280, 280, "Foreground Color");

    // 暂停，等待用户按键
    getch();

    // 关闭图形界面
    closegraph();

    return 0;
}
