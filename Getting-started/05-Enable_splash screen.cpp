/**
 *  Easy Graphics Engine (https://xege.org)
 *  启用启动画面
 *
 *  程序说明:
 *      EGE 的启动画面是 EGE Logo 的淡入动画。拥有三个参数的 initgraph(),
 *    第三个参数是 init_mode(初始化模式，各模式以二进制位进行组合)，如果
 *    想启用 EGE 的启动画面，只需加入 INIT_WITHLOGO 模式即可:
 *      initgraph(witdh, height, INIT_WITHLOGO)
 *
 *  相关函数:
 *      initgraph(width, height, init_mode): 初始化图形环境，创建指定大小窗口
 */

#include <stdio.h>
#include <graphics.h>


int main()
{
    // 初始化，窗口设置为 640x480 大小，启用启动画面
    initgraph(640, 480, INIT_WITHLOGO);

    // 设置背景色为白色
    setbkcolor(WHITE);

    // 延时 2 秒后关闭图形界面
    delay_ms(2000);
    closegraph();

    return 0;
}
