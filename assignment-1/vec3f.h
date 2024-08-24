#ifndef VEC3F_H
#define VEC3F_H

namespace my {
    class Vec3f{
    public:
        // Contructors
        Vec3f();
        Vec3f(float, float, float);

        // Operators
        float &operator[](int index);
        float operator[](int index) const;
        bool operator==(const Vec3f& other) const;
        bool operator!=(const Vec3f& other) const;
        Vec3f& operator+=(const Vec3f &other);
        Vec3f operator+(const Vec3f &other) const;
        Vec3f operator-() const;
        
        // Friend function for dot product
        friend float dot(const Vec3f& v1, const Vec3f& v2);

    private:
        float elements[3];
    };
}



#endif
