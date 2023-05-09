#pragma once

enum class DIR {
	sus = 0,
	dreapta = 1,
	stanga = 2,
	jos = 3,
	null = 4,
};

inline bool eInRaza(float centru, float raza, float nr) {
	return (centru - raza <= nr && centru + raza >= nr);
}