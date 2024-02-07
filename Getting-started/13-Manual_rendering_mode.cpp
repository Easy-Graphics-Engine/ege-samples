/**
 *  Easy Graphics Engine (https://xege.org)
 *  手动渲染模式
 *
 *  预备知识:
 *          EGE 采用双缓冲设计，有两个缓冲区：前台缓冲区和后台缓冲区，前台缓冲区用于显示，
 *      后台缓冲区用于绘图。绘图操作都是在后缓冲区中进行，想要将绘制的内容显示出来，需
 *      要将后台缓冲区中的内容复制到前台缓冲区。
 *
 *      EGE 中的两种渲染模式：
 *          1. 自动渲染模式(默认)：自动触发复制缓冲区操作，适合简单的绘图操作，由于触发时
 *             间与帧不同步，画面容易产生闪烁，因此不适合做动画。
 *          2. 手动渲染模式: 推荐使用的模式，复制缓冲区操作由用户主动触发，可以减少复制操作
 *             以及画面闪烁。简单绘图、复杂绘图以及动画都可以使用此模式。
 *
 *      EGE 中设置渲染模式的方式：
 *          1. 在初始化模式中设置，initgraph()函数的第三个参数，添加 INIT_RENDERMANUAL 即为
 *             手动渲染默认，如果不设置，则为默认的自动渲染模式。
 *          2. 在 setrendermode() 函数中设置(RENDER_AUTO:自动渲染, RENDER_MANUAL:手动渲染)
 *  程序说明:
 *
 *
 *  相关函数及宏:
 *      initgraph():        初始化图形环境, 创建指定大小的窗口，可以指定初始化模式
 *      setrendermode():    设置渲染模式
 */

#include <graphics.h>

// 复杂绘图操作
void complexDraw( int width, int height, color_t color, const char* text);

int main()
{
    // 初始化图形环境，设置手动渲染模式
    initgraph(640, 480, INIT_RENDERMANUAL);

    // 修改为自动渲染模式，在自动渲染模式下进行复杂绘图操作
    setrendermode(RENDER_AUTO);
    complexDraw( 640, 480, EGERGB(135, 206, 250), "Auto Render");

    // 修改为手动渲染模式，在手动渲染模式下进行绘图操作
    setrendermode(RENDER_MANUAL);
    complexDraw(640, 480, EGERGB(0x48, 0xD1, 0xCC), "Manual Render");

    // 延时 1 秒后关闭
    delay_ms(1000);
    closegraph();

    return 0;
}

// 复杂绘图操作
void complexDraw(int width, int height, color_t color, const char* text)
{
    setbkcolor(EGEARGB(255, 40, 44, 52));   // 设置暗色背景色

    int gridSide = 20;              // 格子边长
    int rowCnt = height / gridSide; // 行数
    int colCnt = width / gridSide;  // 列数
    int padding = 2;                // 内部填充边距
    bool exit = false;
    int frameCount = 0;

    // 设置文本样式
    setfont(48, 0, "SimHei");                   // 黑体, 高 48
    setbkmode(TRANSPARENT);                     // 文本背景透明
    settextjustify(CENTER_TEXT, CENTER_TEXT);   // 居中对齐

    // 帧循环
    for ( ; is_run() && !exit; delay_fps(60)) {
        cleardevice();

        for (int row = 0; row < rowCnt; row++) {
            for (int col = 0; col < colCnt; col++) {
                // 计算格子对应的透明度
                int alpha = (255 * row / (rowCnt - 1) +  255 * col / (colCnt - 1)) / 2;

                // 修改 ARGB 中的透明度，并设置填充颜色
                setfillcolor(EGEACOLOR(alpha, color));

                // 计算格子位置
                int x = 640 * col / colCnt + padding;
                int y = 480 * row / rowCnt + padding;
                int w  = gridSide - 2 * padding;
                int h = gridSide - 2 * padding;

                // 对应位置上绘制一个矩形
                ege_fillrect(x, y, w, h);
            }
        }

        // 在窗口中心位置输出文本
        setcolor(WHITE);
        xyprintf(width / 2, height / 2, text);

        if (++frameCount > 60 * 2)
            exit = true;
    }
}
