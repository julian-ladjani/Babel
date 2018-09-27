/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** Size.hpp
*/

#ifndef SIZE_HPP_
#define SIZE_HPP_

class Size {
	public:
		Size(int x = 0, int y = 0, int z = 0);
		~Size();
		int getX() const;
		int getY() const;
		int getZ() const;
		void setX(int x);
		void setY(int y);
		void setZ(int z);

	protected:
		int X;
		int Y;
		int Z;
	private:
};

#endif /* !SIZE_HPP_ */
