# MFC_XListBox
一个自定义的MFC CListBox类，可为每一行设置不同的文字颜色和背景颜色，根据内容高度滚动条会自动调整。可支持扩展菜单。可以写日志文件。 

将下面4个文件拷贝进你的项目就能复用：
* XListBox.cpp
* XListBox.h
* Clipboard.cpp
* Clipboard.h

**重要：**  
确保ListBox的属性设置了：LBS_OWNERDRAWFIXED | LBS_HASSTRINGS  

Thanks to Hans Dietrich.  
[Original Article](https://www.codeproject.com/Articles/2001/XListBox-Owner-draw-CListBox-with-selectable-text)