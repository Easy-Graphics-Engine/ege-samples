/**
 *  Easy Graphics Engine (https://xege.org)
 *  第一个 ege 图形程序
 *
 *  程序说明:
 *      最简单的 ege 程序, 仅包含图形窗口的创建与关闭, 无没有绘图操作
 *
 *  相关函数:
 *      initgraph():  初始化图形环境, 创建指定大小的窗口
 *      closegraph(): 关闭图形界面
 */

#include <graphics.h>

int main()
{
    initgraph(640, 480);    // 初始化，窗口设置为 640x480 大小
    getch();                // 等待用户按键
    closegraph();           // 关闭图形界面

    return 0;
}
