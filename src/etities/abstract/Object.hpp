#ifndef OBJECT_H_DEFINED
#define OBJECT_H_DEFINED

// Abstact class implementing base Object interface.
// All etities must derive from this one to ensure base
// method for all objects.
// Usefull in object factories.


class Object {
public:
    virtual get_width() = 0;
    virtual get_height() = 0;
    virtual get_x_position() = 0;
    virtual get_y_position() = 0;
    virtual set_width() = 0;
    virtual set_height() = 0;
    virtual set_x_position() = 0;
    virtual set_y_position() = 0;
};

#endif