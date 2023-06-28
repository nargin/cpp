#pragma once

#include <iostream>

template <typename Sw>
void swap(Sw &a, Sw &b) {
	Sw tmp = a;
	a = b;
	b = tmp;
}

template <typename Mi>
Mi min(Mi &a, Mi &b) {
	if (a < b)
		return a;
	return b;
}

template <typename Ma>
Ma max(Ma &a, Ma &b) {
	if (a > b)
		return a;
	return b;
}