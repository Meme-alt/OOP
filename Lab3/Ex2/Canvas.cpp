#include "Canvas.h"
Canvas::Canvas(int a, int b) {
	width = a;
	height = b;
	can = new char* [a];
	for (int i = 0;i < a;i++) {
		can[i] = new char[b];
		memset(can[i], ' ', b);
	}
}
void Canvas::DrawCircle(int x, int y, int ray, char ch) {
	for (int i = x - ray;i <= x + ray;i++) {
		for (int j = y - ray;j <= y + ray;j++) {
			int dx = i - x;
			int dy = j - y;
			if (abs(dx * dx + dy * dy - ray * ray) <= 2)
				if (i >= 0 && i < width && j >= 0 && j < height)
					SetPoint(i, j, ch);
		}
	}
}
void Canvas::FillCircle(int x, int y, int ray, char ch) {
	for (int i = x - ray;i <= x + ray;i++) {
		for (int j = y - ray;j <= y + ray;j++) {
			int dx = i - x;
			int dy = j - y;
			if (dx * dx + dy * dy <= ray * ray)
				if (i >= 0 && i < width && j >= 0 && j < height)
					SetPoint(i, j, ch);
		}
	}
}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
	DrawLine(left, top, right, top, ch);
	DrawLine(right, top, right, bottom, ch);
	DrawLine(right, bottom, left, bottom, ch);
	DrawLine(left, bottom, left, top, ch);
}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
	for (int i = top + 1;i < bottom; i++) {
		DrawLine(left + 1, i, right - 1, i, ch);
	}
}
void Canvas::SetPoint(int x, int y, char ch) {
	can[x][y] = ch;
}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int sx = (x1 < x2) ? 1 : -1;
	int sy = (y1 < y2) ? 1 : -1;
	int err = dx - dy;

	while (true) {
		SetPoint(x1, y1, ch);
		if (x1 == x2 && y1 == y2) break;
		int e2 = 2 * err;
		if (e2 > -dy) {
			err -= dy;
			x1 += sx;
		}
		if (e2 < dx) {
			err += dx;
			y1 += sy;
		}
	}
}
void Canvas::Print() {
	for (int i = 0; i < height;i++) {
		for (int j = 0; j < width;j++)
			printf("%c", can[i][j]);
		printf("\n");
	}
}
void Canvas::Clear() {
	for (int i = 0; i < height;i++)
		for (int j = 0; j < width;j++)
			can[i][j] = 32;
}
