/**
 *  Easy Graphics Engine (https://xege.org)
 *  文本输出
 *
 *  预备知识:
 *          在 EGE 的图形窗口中，输出文本需要指定位置坐标。文本的颜色由 setcolor() 指定，
 *      文本背景颜色由 setfontbkcolor() 指定，同时，如果使用 setbkcolor() 修改背景色颜色。
 *      那么文本背景颜色也会相应变化文本通常是使用 setbkmode() 设置成透明
 *      背景色。
 *          文本的字体可以使用 setfont() 进行设置。
 *          文本通常使用 xyprintf() 进行输出。

 *  程序说明:
 *      简单地设置文本样式，在窗口的指定位置和指定区域内输出文本。
 *
 *  相关函数:
 *      setcolor():     设置前景颜色(影响线条、图形边框、文本)
 *      setfont():      设置字体
 *      outtextxy():    在指定位置输出文本
 *      xyprintf():     在指定位置输出格式化后的文本
 *      outtextrect():  在指定区域内输出文本
 *      rectprintf():   在指定区域内输出格式化后的文本
 *      textwidth():    计算文本宽度
 *      textheight():   计算文本高度
 *
 *      更多函数查阅文档: https://xege.org/manual/api/font/index.htm
 */

#include <graphics.h>
#include <stdio.h>

int main()
{
    // 初始化图形环境
    initgraph(640, 300, 0);
    setbkcolor(EGERGB(0x30, 0x30, 0x30));   //设置深色背景

    int fontHeight = 48;

    // 设置字体为 "Times New Roman", 高度为 48, 白色
    setfont(fontHeight, 0, "Times New Roman");
    setcolor(WHITE);

    // 在 (16, fontHeight) 处输出文本
    outtextxy(16, 0, "This's a text.");

    // 设置字体为 "黑体", 高度为 40, 淡蓝色
    setcolor(EGERGB(92, 167, 233));
    setfont(26, 0, L"黑体");

    // 在指定位置处输出格式化后的文本
    xyprintf(16, fontHeight + 24, L"这是一段文本:(%d, %d)", 16, fontHeight + 24);

    // 设置字体为 "宋体", 高度为 24, 白色
    setcolor(WHITE);
    setfont(24, 0, L"宋体");

    // 在矩形区域内输出指定文本，文本自动换行，文末不能完全显示的文字不输出
    int x = 300, y = 16, width = 640 - 300 - 16, height = 180;
    rectprintf(x, y, width, height,
        L"    这是显示在矩形区域内的一段长文本，当"
        L"一行文本的宽度超过区域的宽度时文本会自动"
        L"换行。如果矩形区域无法容纳所有文本内容，"
        L"导致末尾的一些字符有部分区域位于矩形范围"
        L"之外，那么这些字符将不会显示。\n"
        L"    因此，如果不想文字显示不完整，需要控"
        L"制好矩形区域高度和输出的文本长度。"
    );

    // 标注矩形区域位置
    rectangle(x, y, x + width, y + height);

    getch();
    closegraph();

    return 0;
}
