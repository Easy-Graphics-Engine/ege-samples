/**
 *  Easy Graphics Engine (https://xege.org)
 *  设置窗口标题
 *
 *  程序说明:
 *      setcaption() 可以设置和修改窗口标题, 窗口初始化前后调用均可调用。
 *
 *  相关函数:
 *      setcaption(): 设置窗口标题
 */

#include <graphics.h>

int main()
{
    // 在前调用，设置窗口初始标题
    setcaption("标题");

    // 初始化，窗口设置为 320x320 大小
    initgraph(320, 320, 0);
    setbkcolor(WHITE);

    // 延时 2 秒
    delay_ms(2000);

    // 在 initgraph() 后调用，修改标题
    setcaption("This's the new caption.");

    // 延时 2 秒后关闭图形界面
    delay_ms(2000);
    closegraph();

    return 0;
}
