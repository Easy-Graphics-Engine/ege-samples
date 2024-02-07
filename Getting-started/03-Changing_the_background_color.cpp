/**
 *  Easy Graphics Engine (https://xege.org)
 *  改变背景色
 *
 *  程序说明:
 *      1. 初始化后，窗口背景色默认为黑色(#000000)
 *      2. 在存在绘制内容的窗口中调用 setbkcolor(), 除了会设置背景色，还会原背景色部分替换
 *      3. 调用 setbkcolor_f() 只设置背景色属性，无实际绘图操作。在调用 cleardevice() 清屏
 *         后，全部像素颜色改为新背景颜色
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
    initgraph(640, 480, 0);

    // 绘制一个矩形
    setfillcolor(CYAN);
    bar(320 - 100, 240 - 50, 320 + 100, 240 + 50);

    // 延时 1.5 秒
    delay_ms(1500);

    // 仔细看这个的效果，通过 setbkcolor() 设置窗口背景色为白色并将原背景色的部分替换
    setbkcolor(WHITE);

    // 延时 1.5 秒
    delay_ms(1500);

    // 使用 setbkcolor_f() 设置窗口背景色为蓝色, 并使用 cleardevice() 将整个窗口内容
    // 以背景色填充
    setbkcolor_f(LIGHTBLUE);
    cleardevice();

    // 延时 1.5 秒
    delay_ms(1500);

    // 关闭图形界面
    closegraph();

    return 0;
}
