/*
Morning gist:

In your own words, answer this very simple question.
"How do you draw?" You have 2 hrs and you can use your own
code as reference and notes. This is an assessable 
question after 4 weeks of graphics.
*/

/*
"How do you draw?"

Before we begin drawing, data buffers need to be created that
OpenGL reads from (vertex and index information). A vertex
struct should be created to hold vertex information. This
struct will hold the position and color of data type vec4.
We need three variables of data type unsigned int. Three
variables are m_VAO, m_VBO, and m_IBO. We also need shader
data (broken into to sources, vsSource and fsSource, which
will be read from a file). When drawing geometry, we need to
create vertices and indices. How many vertices and indices
we need is determined by the geometry we are trying to draw.
Using the plane as an example, we will need 4 vertices and
4 indices. The vertices array will hold the position and color
data. We will need to generate buffers for vbo and ibo. We also
need to generate a vao vertex array. We then bind the vao
vertex array. We then bind buffers and buffer data. Next,
enable vertex attrib arrays and vertex attrib pointers. Then
we reset the bind vertex array and bind buffers (reset them
back to zero). To "draw" the geometry, in our draw function
we use draw elements. In draw elements, we define how we want
to draw the geometry alone with the amount of indices of the
geometry.
*/