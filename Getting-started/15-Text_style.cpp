/**
 *  Easy Graphics Engine (https://xege.org)
 *  文本样式
 *
 *  预备知识:
 *          文本样式包括字体、字体大小、粗细、颜色、对齐、角度、抗锯齿和修饰等。文本样式一经设置，
 *      直到下次更改前都一直有效。
 *          setfont() 是其中最复杂的函数，有多个重载，可以设置除颜色和对齐之外的其它样式。

 *  程序说明:
 *      使用较为复杂的文字样式
 *
 *  相关类型:
 *      LOGFONT: 定义字体属性
 *
 *  相关函数:
 *      setcolor():     设置前景颜色(影响线条、图形边框、文本)
 *      setfont():      设置字体
 *      getfont():      获取字体属性
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
#include <math.h>

int main()
{
    // 初始化图形环境
    int windowWidth = 640, windowHeight = 500;
    initgraph(windowWidth, windowHeight, 0);
    setbkcolor(EGERGB(0x30, 0x30, 0x30));   //设置深色背景

    // --------------------------- 初始文本样式 --------------------------------
    // 设置初始文本样式: 字体"Times New Roman", 高度为 48, 白色，透明背景色
    int fontHeight = 48;
    setfont(fontHeight, 0, "Simsun");
    setbkmode(TRANSPARENT);
    ege_enable_aa(true);

    // ------------------------- 获取初始字体属性 ------------------------------
    LOGFONT baseFont;
    getfont(&baseFont);

    // ------------------------ 初始文本样式下的文本 ---------------------------
    // 初始字体属性输出白色文本
    setcolor(WHITE);
    xyprintf(16, 0, "This's a text.");

    // ------------------- 使用加粗、下划线、斜体字体样式 ----------------------
    // 在初始字体属性的基础上修改
    LOGFONT font;
    font = baseFont;
    font.lfItalic    = TRUE;        // 斜体
    font.lfUnderline = TRUE;        // 下划线
    font.lfWeight    = FW_BOLD;     // 加粗
    setfont(&font);

    // 设置文本颜色并输出
    setcolor(EGERGB(92, 167, 233));
    xyprintf(16, fontHeight, "This's a text.");

    // ------------------ 使用加粗、删除线、斜体字体样式 -----------------------
    // 由上面设置的字体继续修改
    font.lfUnderline = FALSE;       // 取消下划线
    font.lfStrikeOut = TRUE;        // 加删除线
    setfont(&font);
    setcolor(EGERGB(224, 108, 96));
    xyprintf(16, fontHeight * 2, "This's a text.");

    // --------------------------- 居中对齐文本 --------------------------------
    // 设置为初始字体属性
    setfont(&baseFont);
    settextjustify(CENTER_TEXT, CENTER_TEXT);       // 居中对齐
    setcolor(WHITE);
    // 在窗口中心输出文本
    xyprintf(windowWidth / 2, windowHeight / 2 , "This's the Center text.");

    // ---------------------------- 垂直文本 -----------------------------------
    // 设置为初始字体属性
    font = baseFont;
    font.lfEscapement = 900;                // 文本倾斜角度 90.0°
    setfont(&font);
    settextjustify(LEFT_TEXT, TOP_TEXT);    // 左对齐，顶部对齐
    setcolor(EGERGB(152, 195, 121));
    // 在左下角输出垂直文本
    xyprintf(16, windowHeight - 16 , "Vertical text.");

    // ---------------------------- 垂直加粗文本 -------------------------------
    // 设置为初始字体属性
    font = baseFont;
    font.lfEscapement = 900;                // 文本倾斜角度 90.0°
    font.lfWeight     = FW_BOLD;            // 加粗
    setfont(&font);
    settextjustify(LEFT_TEXT, TOP_TEXT);    // 左对齐，顶部对齐
    setcolor(EGERGB(152, 195, 121));
    // 在左下角输出垂直文本
    xyprintf(16 + fontHeight, windowHeight - 16 , "Vertical bold text.");

    // -------------------------- 45° 倾斜文本 ---------------------------------
    // 设置为初始字体属性
    font = baseFont;
    font.lfEscapement = 450;                // 文本倾斜角度 45.0°
    font.lfWeight     = FW_BOLD;            // 加粗
    setfont(&font);
    settextjustify(LEFT_TEXT, TOP_TEXT);    // 左对齐，顶部对齐
    setcolor(EGERGB(203, 154, 102));
    // 在左下角输出倾斜文本
    xyprintf(16 + fontHeight * 2, windowHeight - 48 , "Sloped text.");

    // ---------------------------- 环形文本 -----------------------------------
    font = baseFont;
    font.lfHeight = 28;                         // 设置文本高度
    settextjustify(CENTER_TEXT, TOP_TEXT);      // 设置左对齐，顶部对齐

    double radius = 112.0;                      // 半径
    int cx = 500, cy = 120;                     // 中心坐标

    for (int i = 1; i <= 12; i++) {
        // 计算文本位置
        double rad = -PI / 2.0 + 2.0 * PI * i / 12.0;
        int x = cx + round(radius * cos(rad));
        int y = cy + round(radius * sin(rad));

        // 调整文本角度、颜色
        font.lfEscapement = - 3600 * i / 12;
        setfont(&font);
        setcolor(HSLtoRGB(360.0f * i/ 12, 0.9f, 0.5f));

        xyprintf(x, y, "%d", i);
    }

    // 绘制外圈
    setcolor(WHITE);
    ege_ellipse(cx - radius, cy - radius, 2 * radius, 2 * radius);

// ----------------------------- 文本对齐 --------------------------------------
    int height = 28;
    setfont(height, 0, "Consolas");
    int refx = 420, refy = 460;                     // 参考点坐标
    setcolor(WHITE);                                // 白色文本
    setbkmode(OPAQUE);                              // 文字背景不透明

    // 对齐方式即参考点在文本的位置
    // 1. 左对齐，顶部对齐 (参考点在文本左上角)
    settextjustify(LEFT_TEXT, TOP_TEXT);
    setfontbkcolor(EGEGRAY(0x80));
    xyprintf(refx, refy, "   Left, Top    ");

    // 2. 右对齐，顶部对齐 (参考点在文本右上角)
    settextjustify(RIGHT_TEXT, TOP_TEXT);
    setfontbkcolor(EGEGRAY(0x60));
    xyprintf(refx, refy, "  Right, Top    ");

    // 3. 左对齐，底部对齐 (参考点在文本左下角)
    settextjustify(LEFT_TEXT, BOTTOM_TEXT);
    setfontbkcolor(EGEGRAY(0x60));
    xyprintf(refx, refy, "   Left, Bottom ");

    // 4. 右对齐，底部对齐 (参考点在文本右下角)
    settextjustify(RIGHT_TEXT, BOTTOM_TEXT);
    setfontbkcolor(EGEGRAY(0x80));
    xyprintf(refx, refy, "  Right, Bottom ");

    // 标注参考点
    setfillcolor(EGERGB(203, 154, 102));
    ege_fillellipse(refx - 4.0f, refy - 4.0f, 8.0f, 8.0f);

    // 修改参考点位置
    refy -= 3 * height;

    // 5. 水平居中对齐，顶部对齐 (参考点在文本顶部中间位置)
    settextjustify(CENTER_TEXT, TOP_TEXT);
    setfontbkcolor(EGEGRAY(0x80));
    xyprintf(refx, refy, " Center, Top    ");

    // 6. 水平居中对齐，底部对齐 (参考点在文本底部中间位置)
    settextjustify(CENTER_TEXT, BOTTOM_TEXT);
    setfontbkcolor(EGEGRAY(0x60));
    xyprintf(refx, refy, " Center, Bottom ");

    // 标注参考点
    setfillcolor(EGERGB(152, 195, 112));
    ege_fillellipse(refx - 4.0f, refy  - 4.0f, 8.0f, 8.0f);

    // 修改参考点位置
    refy -= 3 * height;
    // 7. 左对齐，垂直居中对齐 (参考点在文本左边中间位置)
    settextjustify(LEFT_TEXT, CENTER_TEXT);
    setfontbkcolor(EGEGRAY(0x80));
    xyprintf(refx, refy, "   Left, Center ");

    // 8. 右对齐，垂直居中对齐 (参考点在文本右边中间位置)
    settextjustify(RIGHT_TEXT, CENTER_TEXT);
    setfontbkcolor(EGEGRAY(0x60));
    xyprintf(refx, refy, "  Right, Center ");

    // 标注参考点
    setfillcolor(EGERGB(207, 112, 214));
    ege_fillellipse(refx - 4.0f, refy  - 4.0f, 8.0f, 8.0f);
    // -------------------------------------------------------------------------
    getch();
    closegraph();

    return 0;
}
