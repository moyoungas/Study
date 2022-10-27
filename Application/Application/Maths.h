#pragma once

namespace Nmy
{




	struct Vector2
	{

		static Vector2 Zero;
		static Vector2 One;
		static Vector2 Right;
		static Vector2 Left;
		static Vector2 Up;
		static Vector2 Down;


		float x;
		float y;

		Vector2(float x, float y)
		{
			this->x = x;
			this->y = y;
		}


		Vector2 operator + (const Vector2& other)
		{
			Vector2 temp;
			temp.x = this->x + other.x;
			temp.y = this->y + other.y;
			return temp;
		}

		Vector2 operator /(const float other)
		{
			Vector2 temp;
			temp.x = this->x / other;
			temp.y = this->y / other;
			return temp;
		}

		Vector2 operator -(const Vector2& other)
		{
			Vector2 temp;
			temp.x = this->x - other.x;
			temp.y = this->y - other.y;
			return temp;
		}

		Vector2(const Vector2& other) = default;
		Vector2() = default;
		~Vector2() = default;


	};
}