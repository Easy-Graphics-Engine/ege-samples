/**
 *  Easy Graphics Engine (https://xege.org)
 *  设置背景色
 *
 *  程序说明:
 *      1.初始化后, 窗口背景色默认为黑色(#000000)
 *      2.通过 setbkcolor() 设置背景色(会用新的背景色替换掉原背景色像素)
 *      3.通过 setbkcolor_f() 设置背景色属性，之后使用 cleardevice() 将所
 *        有像素颜色设置为背景色
 *
 *  相关函数:
 *      setbkcolor():   设置新背景色并替换旧背景色
 *      setbkcolor_f(): 设置新背景色
 *      cleardevice():  清屏, 以背景色填充整个窗口或图像
 */

#include <graphics.h>

int main()
{
    // 初始化，窗口设置为 640x480 大小
    initgraph(640, 480);

    // 将背景色设置为白色(WHITE: EGE 定义的颜色值)
    // 方式1: 通过 setbkcolor() 设置窗口背景色，同时将颜色为原背景色的像
    //     素替换成新背景色
    setbkcolor(WHITE);

    // 方式2: 通过 setbkcolor_f() 设置窗口背景色，然后使用 cleardevice()
    //     将窗口像素全部设置成新背景色
    setbkcolor_f(WHITE);
    cleardevice();

    getch();        // 等待用户按键
    closegraph();   // 关闭图形界面
    return 0;
}
