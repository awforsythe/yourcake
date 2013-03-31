/** \file
    This test program simply ensures that all of the external dependencies are
    properly built, and that this project is configured to make use of them.
*/

#include "Box2D/Box2D.h"
#include "GL/glfw.h"
#include "ogg/ogg.h"
#include "vorbis/vorbisfile.h"
#include "SOIL.h"
#include "tinyxml.h"

int main()
{
    // Test Box2D
    {
        b2Vec2 gravity(0.0f, -10.0f);
        b2World world(gravity);
    }

    // Test GLFW
    {
        if (glfwInit()) {
            glfwTerminate();
        }
    }

    // Test libogg
    {
        ogg_stream_state os;
        if (ogg_stream_init(&os, 0) == 0) {
            ogg_stream_clear(&os);
        }
    }

    // Test libvorbis
    {
        vorbis_info vi;
        vorbis_info_init(&vi);
        vorbis_info_clear(&vi);
    }

    // Test SOIL
    {
        SOIL_last_result();
    }

    // Test tinyxml
    {
        TiXmlDocument doc;
        TiXmlDeclaration* decl = new TiXmlDeclaration("1.0", "", "");
        TiXmlElement* element = new TiXmlElement("Hello");
        TiXmlText* text = new TiXmlText("World");
        element->LinkEndChild(text);
        doc.LinkEndChild(decl);
        doc.LinkEndChild(element);
    }
}
