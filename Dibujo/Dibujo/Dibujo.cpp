/*---------------------------------------------------------*/
/* ---------Proyecto 02: Dibujo 2D de personajes ----------*/
/*-------Personajes: Xayah y Rakan (League of Legends)-----*/
/*-----------------    2021-1   ---------------------------*/
/*-------Alumno: Reza Chavarria Sergio Gabriel	 ----------*/

#include <glew.h>
#include <glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <shader_m.h>

#include <iostream>

void resize(GLFWwindow* window, int width, int height);
void my_input(GLFWwindow *window);
//Movimiento de la vista
float movX = 0.0f;
float movY = 0.0f;
float movZ = 0.0f;



// settings
// Window size
int SCR_WIDTH = 3800;
int SCR_HEIGHT = 7600;

GLFWmonitor *monitors;
GLuint VBO, VAO, EBO;

void myData(void);
void display(Shader);
void getResolution(void);


//For Keyboard


//Colores
float fondoMoradoR = 0.0313f, fondoMoradoG = 0.05882f, fondoMoradoB = 0.1176f;
float pielR=0.9607f, pielG=0.8823f, pielB=0.8901f;
float cabelloXR = 0.7607f, cabelloXG = 0.1803f, cabelloXB = 0.6196f;
float cabelloRR = 0.01960f, cabelloRG = 0.8431f, cabelloRB = 0.7254f;
float detalleMR = 0.1921f, detalleMG = 0.1019f, detalleMB = 0.3254f;
float orejaR = 0.3333f, orejaG = 0.5607F, orejaB = 0.6156f;
float detalleR = 0.2000f, detalleG = 0.1000f, detalleB = 0.3000f;
float detalleR1 = 0.3000f, detalleG1 = 0.2000f, detalleB1 = 0.4000f;
float doradoR = 0.9450f, doradoG = 0.7490f, doradoB = 0.3490f;
float orejasR=0.6431f, orejasG=0.1529f, orejasB=0.7960f;
float ojosXR = 0.8549f, ojosXG = 0.4392f, ojosXB = 1.0f;
float sombrasR=0.8901f, sombrasG=0.7176f, sombrasB=0.7843f;

float lineasCabelloXR=0.4352f, lineasCabelloXG=0.0666f, lineasCabelloXB=0.3176f;
float lineasCabelloRR = 0.047f, lineasCabelloRG = 0.2745f, lineasCabelloRB = 0.4117f;
void getResolution()
{
	const GLFWvidmode * mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

	SCR_WIDTH = mode->width;
	SCR_HEIGHT = (mode->height) - 80;
}

void myData()
{
	GLfloat vertices[] = {
		//Position				//Color
		-15.0f,7.0f,0.0f,	fondoMoradoR,fondoMoradoG,fondoMoradoB,//0
		0.0f,7.0f,0.0f,		fondoMoradoR,fondoMoradoG,fondoMoradoB,//1
		15.0f,7.0f,0.0f,	fondoMoradoR,fondoMoradoG,fondoMoradoB,//2
		15.0f,-7.0f,0.0f,	fondoMoradoR,fondoMoradoG,fondoMoradoB,//3
		0.0f,-7.0f,0.0f,	fondoMoradoR,fondoMoradoG,fondoMoradoB,//4
		-15.0f,-7.0f,0.0f,	fondoMoradoR,fondoMoradoG,fondoMoradoB,//5

		5.0f,0.0f,0.0f,		0.4599f, 0.0941f	,0.5882f,//6
		-5.0f,0.0f,0.0f,	0.0f	,0.3450f	,0.5882f,//7

		//Piel Xayah
		2.4f,0.0f,0.1f,		pielR,pielG,pielB,//8
		2.55f,-1.0f,0.1f,	pielR,pielG,pielB,//9
		3.0f,-1.5f,0.1f,	pielR,pielG,pielB,//10
		3.4f,-2.0f,0.1f,	pielR,pielG,pielB,//11
		4.0f,-2.5f,0.1f,	pielR,pielG,pielB,//12
		4.3f,-2.7f,0.1f,	pielR,pielG,pielB,//13
		5.0f,-2.2f,0.1f,	pielR,pielG,pielB,//14
		5.2f,-2.0f,0.1f,	pielR,pielG,pielB,//15
		6.0f,-1.0f,0.1f,	pielR,pielG,pielB,//16
		6.0f,2.0f,0.1f,		pielR,pielG,pielB,//17
		2.4f,2.0f,0.1f,		pielR,pielG,pielB,//18
		4.0f,0.0f,0.1f,		pielR,pielG,pielB,//19

		//Cuello
		4.5f,-2.4f,0.09f,	pielR,pielG,pielB,//20
		5.0f,-3.2f,0.09f,	pielR,pielG,pielB,//21
		5.7f,-2.5f,0.09f,	pielR,pielG,pielB,//22
		6.0f,-1.0f,0.09f,	pielR,pielG,pielB,//23
		5.3f,-1.3f,0.09f,	pielR,pielG,pielB,//24

		//Piel Rakan
		-5.8f,-1.0f,0.1f,	pielR,pielG,pielB,//25
		-5.3f,-2.0f,0.1f,	pielR,pielG,pielB,//26
		-5.0f,-2.2f,0.1f,	pielR,pielG,pielB,//27
		-4.8f,-2.5f,0.1f,	pielR,pielG,pielB,//28
		-4.0f,-2.5f,0.1f,	pielR,pielG,pielB,//29
		-3.1f,-2.0f,0.1f,	pielR,pielG,pielB,//30
		-2.5f,-1.0f,0.1f,	pielR,pielG,pielB,//31
		-2.3f,-0.5f,0.1f,	pielR,pielG,pielB,//32
		-2.3f,0.0f,0.1f,	pielR,pielG,pielB,//33
		-2.0f,0.5f,0.1f,	pielR,pielG,pielB,//34
		-2.0f,3.0f,0.1f,	pielR,pielG,pielB,//35
		-6.0f,3.0f,0.1f,	pielR,pielG,pielB,//36
		-4.0f,0.0f,0.1f,	pielR,pielG,pielB,//37

		//Cuello
		-5.8f,-1.0f,0.09f,	pielR,pielG,pielB,//38
		-5.0f,-5.0f,0.09f,	pielR,pielG,pielB,//39
		-4.0f,-2.5f,0.09f,	pielR,pielG,pielB,//40
		-4.7f,-2.9f,0.09f,	pielR,pielG,pielB,//41

		//Cabello Xayah

		3.4f, 1.5f,0.2f,	cabelloXR,cabelloXG,cabelloXB,//42
		3.5f, 2.0f,0.2f,	cabelloXR,cabelloXG,cabelloXB,//43
		3.9f, 3.0f,0.2f,	cabelloXR,cabelloXG,cabelloXB,//44
		4.0f, 3.2f,0.2f,	cabelloXR,cabelloXG,cabelloXB,//45
		4.3f, 3.5f,0.2f,	cabelloXR,cabelloXG,cabelloXB,//46
		5.0f, 3.8f,0.2f,	cabelloXR,cabelloXG,cabelloXB,//47
		5.5f, 3.6f,0.2f,	cabelloXR,cabelloXG,cabelloXB,//48
		6.0f, 3.2f,0.2f,	cabelloXR,cabelloXG,cabelloXB,//49
		6.2f, 3.0f,0.2f,	cabelloXR,cabelloXG,cabelloXB,//50
		6.9f, 2.5f,0.2f,	cabelloXR,cabelloXG,cabelloXB,//51
		5.9f, 1.0f,0.2f,	cabelloXR,cabelloXG,cabelloXB,//52
		5.0f, 2.0f,0.2f,	cabelloXR,cabelloXG,cabelloXB,//53
		4.0f, 2.0f,0.2f,	cabelloXR,cabelloXG,cabelloXB,//54
		5.0f, 3.0f,0.2f,	cabelloXR,cabelloXG,cabelloXB,//55

		4.3f, 3.5f,0.2f,	cabelloXR,cabelloXG,cabelloXB,//56
		4.0f, 3.6f,0.2f,	cabelloXR,cabelloXG,cabelloXB,//57
		3.6f, 3.5f,0.2f,	cabelloXR,cabelloXG,cabelloXB,//58
		3.0f, 3.2f,0.2f,	cabelloXR,cabelloXG,cabelloXB,//59
		2.7f, 3.0f,0.2f,	cabelloXR,cabelloXG,cabelloXB,//60
		2.2f, 2.5f,0.2f,	cabelloXR,cabelloXG,cabelloXB,//61
		3.4f, 1.5f,0.2f,	cabelloXR,cabelloXG,cabelloXB,//62
		3.2f, 3.0f,0.2f,	cabelloXR,cabelloXG,cabelloXB,//63

		6.9f, 2.5f,0.2f,	cabelloXR,cabelloXG,cabelloXB,//64
		7.5f, 1.0f,0.2f,	cabelloXR,cabelloXG,cabelloXB,//65
		7.5f, 0.0f,0.2f,	cabelloXR,cabelloXG,cabelloXB,//66
		7.4f, -1.0f,0.2f,	cabelloXR,cabelloXG,cabelloXB,//67
		6.0f, -1.0f,0.2f,	cabelloXR,cabelloXG,cabelloXB,//68
		5.9f, 1.0f,0.2f,	cabelloXR,cabelloXG,cabelloXB,//69
		7.0f, 0.5f,0.2f,	cabelloXR,cabelloXG,cabelloXB,//70

		7.4f, -1.0f,0.2f,	cabelloXR,cabelloXG,cabelloXB,//71
		7.3f, -2.0f,0.2f,	cabelloXR,cabelloXG,cabelloXB,//72
		7.2f, -3.0f,0.2f,	cabelloXR,cabelloXG,cabelloXB,//73
		7.3f, -4.0f,0.2f,	cabelloXR,cabelloXG,cabelloXB,//74
		5.4f, -4.0f,0.2f,	cabelloXR,cabelloXG,cabelloXB,//75
		5.5f, -3.0f,0.2f,	cabelloXR,cabelloXG,cabelloXB,//76
		5.7f, -2.0f,0.2f,	cabelloXR,cabelloXG,cabelloXB,//77
		6.0f, -1.0f,0.2f,	cabelloXR,cabelloXG,cabelloXB,//78
		6.5f, -2.5f,0.2f,	cabelloXR,cabelloXG,cabelloXB,//79

		7.3f, -4.0f,0.2f,	cabelloXR,cabelloXG,cabelloXB,//80
		7.5f, -4.5f,0.2f,	cabelloXR,cabelloXG,cabelloXB,//81
		8.0f, -5.0f,0.2f,	cabelloXR,cabelloXG,cabelloXB,//82
		8.7f, -5.5f,0.2f, cabelloXR, cabelloXG, cabelloXB,//83
		8.0f, -5.9f, 0.2f, cabelloXR, cabelloXG, cabelloXB,//84
		7.0f, -5.9f, 0.2f, cabelloXR, cabelloXG, cabelloXB,//85
		6.0f, -5.5f, 0.2f, cabelloXR, cabelloXG, cabelloXB,//86
		5.5f, -5.0f, 0.2f, cabelloXR, cabelloXG, cabelloXB,//87
		5.4f, -4.0f, 0.2f, cabelloXR, cabelloXG, cabelloXB,//88
		7.0f, -5.0f, 0.2f, cabelloXR, cabelloXG, cabelloXB,//89

		6.0f,0.9f,0.25f,	cabelloXR, cabelloXG, cabelloXB,//90
		6.0f,1.1f,0.25f,	cabelloXR, cabelloXG, cabelloXB,//91
		6.3f,0.0f,0.25f,	cabelloXR, cabelloXG, cabelloXB,//92
		6.0f,-0.7f,0.25f, cabelloXR, cabelloXG, cabelloXB,//93
		5.5f,-0.8f,0.25f, cabelloXR, cabelloXG, cabelloXB,//94
		5.0f,-0.5f,0.25f, cabelloXR, cabelloXG, cabelloXB,//95
		5.5f,-0.4f,0.25f, cabelloXR, cabelloXG, cabelloXB,//96
		5.6f,0.0f,0.25f, cabelloXR, cabelloXG, cabelloXB,//97
		5.9f,0.5f,0.25f, cabelloXR, cabelloXG, cabelloXB,//98
		5.9f,0.9f,0.25f,	cabelloXR, cabelloXG, cabelloXB,//99
		6.0f,0.0f,0.25f, cabelloXR, cabelloXG, cabelloXB,//100


		2.3f,2.5f,0.25f, cabelloXR, cabelloXG, cabelloXB,//101
		2.0f,2.2f,0.25f, cabelloXR, cabelloXG, cabelloXB,//102
		1.8f,2.0f,0.25f, cabelloXR, cabelloXG, cabelloXB,//103
		1.5f,1.5f,0.25f, cabelloXR, cabelloXG, cabelloXB,//104
		1.3f,1.0f,0.25f, cabelloXR, cabelloXG, cabelloXB,//105
		1.2f,0.5f,0.25f, cabelloXR, cabelloXG, cabelloXB,//106
		1.3f,0.0f,0.25f, cabelloXR, cabelloXG, cabelloXB,//107
		1.5f,-0.5f,0.25f, cabelloXR, cabelloXG, cabelloXB,//108
		2.0f,-1.0f,0.25f, cabelloXR, cabelloXG, cabelloXB,//109
		2.5f,-1.2f,0.25f, cabelloXR, cabelloXG, cabelloXB,//110
		3.0f,-1.3f,0.25f, cabelloXR, cabelloXG, cabelloXB,//111
		3.4f,-1.1f,0.25f, cabelloXR, cabelloXG, cabelloXB,//112
		3.2f,-1.0f,0.25f, cabelloXR, cabelloXG, cabelloXB,//113
		3.0f,-0.5f,0.25f, cabelloXR, cabelloXG, cabelloXB,//114
		2.9f,0.0f,0.25f, cabelloXR, cabelloXG, cabelloXB,//115
		2.85f,0.5f,0.25f, cabelloXR, cabelloXG, cabelloXB,//116
		2.9f,1.0f,0.25f, cabelloXR, cabelloXG, cabelloXB,//117
		3.0f,1.3f,0.25f, cabelloXR, cabelloXG, cabelloXB,//118
		3.3f,1.6f,0.25f, cabelloXR, cabelloXG, cabelloXB,//119
		2.0f,0.5f,0.25f, cabelloXR, cabelloXG, cabelloXB,//120


		3.4f,2.0f,0.25f, cabelloXR, cabelloXG, cabelloXB, //121
		3.5f,1.8f,0.25f, cabelloXR, cabelloXG, cabelloXB,//122
		4.0f,1.8f,0.25f, cabelloXR, cabelloXG, cabelloXB,//123
		4.4f,1.85f,0.25f, cabelloXR, cabelloXG, cabelloXB,//124
		5.0f,1.6f, 0.25f, cabelloXR, cabelloXG, cabelloXB,//125
		5.4f,1.0f,0.25f, cabelloXR, cabelloXG, cabelloXB,//126
		5.6f,0.9f,0.25f, cabelloXR, cabelloXG, cabelloXB,//127
		6.0f,1.0f,0.25f, cabelloXR, cabelloXG, cabelloXB,//128
		5.0f,2.5f,0.25f, cabelloXR, cabelloXG, cabelloXB,//129

		//Pelo atras
		3.0f,-1.5f,0.08f, cabelloXR, cabelloXG, cabelloXB,//130
		3.05f,-2.0f,0.08f, cabelloXR, cabelloXG, cabelloXB,//131
		3.1f,-3.0f,0.08f, cabelloXR, cabelloXG, cabelloXB,//132
		3.0f,-4.0f,0.08f, cabelloXR, cabelloXG, cabelloXB,//133
		4.6f,-4.0f,0.08f, cabelloXR, cabelloXG, cabelloXB,//134
		4.7f,-3.5f,0.08f, cabelloXR, cabelloXG, cabelloXB,//135
		4.75f,-3.0f, 0.08f, cabelloXR, cabelloXG, cabelloXB,//136
		4.6f,-2.5f,0.08f, cabelloXR, cabelloXG, cabelloXB,//137
		4.0f,-3.0f,0.08f, cabelloXR, cabelloXG, cabelloXB,//138


		3.0f, -4.0f, 0.08f, cabelloXR, cabelloXG, cabelloXB,//139
		2.6f, -4.2f, 0.08f, cabelloXR, cabelloXG, cabelloXB,//140
		2.4f,-4.2f,0.08f, cabelloXR, cabelloXG, cabelloXB,//141
		2.2f,-4.0f,0.08f, cabelloXR, cabelloXG, cabelloXB,//142
		1.0f,-4.0f,0.08f, cabelloXR, cabelloXG, cabelloXB,//143
		0.95f,-4.5f,0.08f, cabelloXR, cabelloXG, cabelloXB,//144
		1.0f,-5.0f,0.08f, cabelloXR, cabelloXG, cabelloXB,//145
		1.2f,-5.4f,0.08f, cabelloXR, cabelloXG, cabelloXB,//146
		1.5f,-5.5f,0.08f, cabelloXR, cabelloXG, cabelloXB,//147
		2.0f,-5.6f,0.08f, cabelloXR, cabelloXG, cabelloXB,//148
		2.5f,-5.4f,0.08f, cabelloXR, cabelloXG, cabelloXB,//149
		3.0f,-5.3f,0.08f, cabelloXR, cabelloXG, cabelloXB,//150
		3.5f,-5.1f,0.08f, cabelloXR, cabelloXG, cabelloXB,//151
		4.0f,-4.8f,0.08f, cabelloXR, cabelloXG, cabelloXB,//152
		4.3f,-4.4f,0.08f, cabelloXR, cabelloXG, cabelloXB,//153
		4.6f, -4.0f, 0.08f, cabelloXR, cabelloXG, cabelloXB,//154
		2.5f,-5.0f,0.08f, cabelloXR, cabelloXG, cabelloXB,//155

		2.2f, -4.0f, 0.08f, cabelloXR, cabelloXG, cabelloXB,//156
		2.0f,-3.8f,0.08f, cabelloXR, cabelloXG, cabelloXB,//157
		1.9f,-3.7f,0.08f, cabelloXR, cabelloXG, cabelloXB,//158
		1.85f,-3.6f, 0.08f, cabelloXR, cabelloXG, cabelloXB,//159
		1.9f,-3.5f,0.08f, cabelloXR, cabelloXG, cabelloXB,//160
		2.0f,-3.2f,0.08f, cabelloXR, cabelloXG, cabelloXB,//161
		1.5f,-3.5f,0.08f, cabelloXR, cabelloXG, cabelloXB,//162
		1.2f,-3.8f,0.08f, cabelloXR, cabelloXG, cabelloXB,//163
		1.0f, -4.0f, 0.08f, cabelloXR, cabelloXG, cabelloXB,//164
		1.5f,-3.65f,0.08f, cabelloXR, cabelloXG, cabelloXB,//165


		//Orejas
		4.8f,1.0f,0.08f, cabelloXR, cabelloXG, cabelloXB,//166
		2.5f,6.5f,0.08f, cabelloXR, cabelloXG, cabelloXB,//167
		2.3f,6.0f,0.08f, cabelloXR, cabelloXG, cabelloXB,//168
		2.0f,4.5f,0.08f, cabelloXR, cabelloXG, cabelloXB,//169
		1.7f,4.6f,0.08f, cabelloXR, cabelloXG, cabelloXB,//170
		1.5f,4.0f,0.08f, cabelloXR, cabelloXG, cabelloXB,//171
		1.4f,3.0f,0.08f, cabelloXR, cabelloXG, cabelloXB,//172
		1.3f,2.6f,0.08f, cabelloXR, cabelloXG, cabelloXB,//173
		1.4f, 2.0f, 0.08f, cabelloXR, cabelloXG, cabelloXB,//174
		2.5f,0.0f,0.08f, cabelloXR, cabelloXG, cabelloXB,//175

		6.0f,1.0f,0.08f, cabelloXR, cabelloXG, cabelloXB,//176
		7.0f,1.0f,0.08f, cabelloXR, cabelloXG, cabelloXB,//177
		7.4f,2.5f,0.08f, cabelloXR, cabelloXG, cabelloXB,//178
		7.0f,2.1f,0.08f, cabelloXR, cabelloXG, cabelloXB,//179
		7.3f,3.2f,0.08f, cabelloXR, cabelloXG, cabelloXB,//180
		6.8f,3.1f,0.08f, cabelloXR, cabelloXG, cabelloXB,//181
		6.9f,4.0f,0.08f, cabelloXR, cabelloXG, cabelloXB,//182
		6.5f,4.6f,0.08f, cabelloXR, cabelloXG, cabelloXB,//183
		6.0f,5.0f,0.08f, cabelloXR, cabelloXG, cabelloXB,//184
		5.5f,5.7f,0.08f, cabelloXR, cabelloXG, cabelloXB,//185
		5.0f,6.0f,0.08f, cabelloXR, cabelloXG, cabelloXB,//186
		4.3f,6.2f,0.08f, cabelloXR, cabelloXG, cabelloXB,//187
		5.0f,3.8f,0.08f, cabelloXR, cabelloXG, cabelloXB,//188


		//cabello Rakan
		-5.5f, 1.4f, 0.2f, cabelloRR, cabelloRG, cabelloRB,//189
		-7.0f, 2.5f, 0.2f, cabelloRR, cabelloRG, cabelloRB,//190
		-5.7f, 1.0f,0.2f, cabelloRR, cabelloRG, cabelloRB,//191

		-5.0f,1.9f,0.2f, cabelloRR, cabelloRG, cabelloRB,//192
		-5.5f,1.5f,0.2f, cabelloRR, cabelloRG, cabelloRB,//193
		-6.7f,2.5f,0.2f, cabelloRR, cabelloRG, cabelloRB,//194
		-6.5f,2.8f,0.2f, cabelloRR, cabelloRG, cabelloRB,//195

		-4.4f,2.2f,0.2f, cabelloRR, cabelloRG, cabelloRB,//196
		-5.7f,3.8f,0.2f, cabelloRR, cabelloRG, cabelloRB,//197
		-6.4f,3.4f,0.2f, cabelloRR, cabelloRG, cabelloRB,//198
		-6.5f,2.8f,0.2f, cabelloRR, cabelloRG, cabelloRB,//199
		-5.3f,1.5f,0.2f, cabelloRR, cabelloRG, cabelloRB,//200

		-3.5f,2.0f,0.2f, cabelloRR, cabelloRG, cabelloRB,//201
		-4.0f,2.2f,0.2f, cabelloRR, cabelloRG, cabelloRB,//202
		-5.0f,2.7f,0.2f, cabelloRR, cabelloRG, cabelloRB,//203
		-5.3f,3.0f,0.2f, cabelloRR, cabelloRG, cabelloRB,//204
		-5.8f,3.8f,0.2f, cabelloRR, cabelloRG, cabelloRB,//205
		-5.9f,4.0f,0.2f, cabelloRR, cabelloRG, cabelloRB,//206
		-5.8f,4.4f,0.2f, cabelloRR, cabelloRG, cabelloRB,//207
		-5.0f,4.3f,0.2f, cabelloRR, cabelloRG, cabelloRB,//208
		-4.5f,4.0f,0.2f, cabelloRR, cabelloRG, cabelloRB,//209
		-4.0f,3.5f,0.2f, cabelloRR, cabelloRG, cabelloRB,//210
		-3.8f,3.0f,0.2f, cabelloRR, cabelloRG, cabelloRB,//211
		-3.5f,2.5f,0.2f, cabelloRR, cabelloRG, cabelloRB,//212
		-4.5f,3.0f,0.2f, cabelloRR, cabelloRG, cabelloRB,//213

		-3.0f,2.0f,0.2f, cabelloRR, cabelloRG, cabelloRB,//214
		-2.0f,3.0f,0.2f, cabelloRR, cabelloRG, cabelloRB,//215
		-2.0f,3.2f,0.2f, cabelloRR, cabelloRG, cabelloRB,//216
		-2.5f,4.0f,0.2f, cabelloRR, cabelloRG, cabelloRB,//217
		-3.0f,4.4f,0.2f, cabelloRR, cabelloRG, cabelloRB,//218
		-4.0f,5.0f,0.2f, cabelloRR, cabelloRG, cabelloRB,//219
		-4.5f,5.2f,0.2f, cabelloRR, cabelloRG, cabelloRB,//220
		-5.0f,5.0f,0.2f, cabelloRR, cabelloRG, cabelloRB,//221
		-5.5f,4.3f,0.2f, cabelloRR, cabelloRG, cabelloRB,//222
		-3.5f,2.2f,0.2f, cabelloRR, cabelloRG, cabelloRB,//223

		-3.0f, 2.0f, 0.2f, cabelloRR, cabelloRG, cabelloRB,//224
		-1.4f,3.0f,0.2f, cabelloRR, cabelloRG, cabelloRB,//225
		-1.8f,4.0f,0.2f, cabelloRR, cabelloRG, cabelloRB,//226
		-2.0f,4.3f,0.2f, cabelloRR, cabelloRG, cabelloRB,//227
		-2.5f,4.3f,0.2f, cabelloRR, cabelloRG, cabelloRB,//228
		-3.0f,4.6f,0.2f, cabelloRR, cabelloRG, cabelloRB,//229
		-3.5f,4.3f,0.2f, cabelloRR, cabelloRG, cabelloRB,//230

		-1.3f, 3.0f, 0.2f, cabelloRR, cabelloRG, cabelloRB,//231
		-1.0f,2.5f,0.2f, cabelloRR, cabelloRG, cabelloRB,//232
		-0.8f,2.0f,0.2f, cabelloRR, cabelloRG, cabelloRB,//233
		-0.5f,1.5f,0.2f, cabelloRR, cabelloRG, cabelloRB,//234
		-0.4f,1.0f,0.2f, cabelloRR, cabelloRG, cabelloRB,//235
		-0.4f,0.0f,0.2f, cabelloRR, cabelloRG, cabelloRB,//236
		-1.6f,0.0f,0.2f, cabelloRR, cabelloRG, cabelloRB,//237
		-1.6f,1.0f,0.2f, cabelloRR, cabelloRG, cabelloRB,//238
		-1.7f,1.5f,0.2f, cabelloRR, cabelloRG, cabelloRB,//239
		-1.8f,2.0f,0.2f, cabelloRR, cabelloRG, cabelloRB,//240
		-2.0f,2.1f,0.2f, cabelloRR, cabelloRG, cabelloRB,//241
		-3.0f,2.0f,0.2f, cabelloRR, cabelloRG, cabelloRB,//242

		-0.4f, 0.0f, 0.2f, cabelloRR, cabelloRG, cabelloRB,//243
		-0.5f, -0.5f, 0.2f, cabelloRR, cabelloRG, cabelloRB,//244
		-0.7f, -1.0f, 0.2f, cabelloRR, cabelloRG, cabelloRB,//245
		-1.0f, -1.5f, 0.2f, cabelloRR, cabelloRG, cabelloRB,//246
		-1.2f, -2.0f,0.2f, cabelloRR, cabelloRG, cabelloRB,//247
		-2.0f, -2.8f,0.2f, cabelloRR, cabelloRG, cabelloRB,//248
		-2.3f,-3.0f,0.2f, cabelloRR, cabelloRG, cabelloRB,//249
		-2.0f,-2.2f,0.2f, cabelloRR, cabelloRG, cabelloRB,//250
		-1.8f,-2.0f,0.2f, cabelloRR, cabelloRG, cabelloRB,//251
		-1.6f,-1.0f,0.2f, cabelloRR, cabelloRG, cabelloRB,//252
		-1.6f,0.0f,0.2f, cabelloRR, cabelloRG, cabelloRB,//253

		//Mechones
		-3.2f,-2.0f,0.08f, cabelloRR, cabelloRG, cabelloRB,//254
		-3.1f,-3.0f,0.08f, cabelloRR, cabelloRG, cabelloRB,//255
		-2.8f,-4.0f,0.08f, cabelloRR, cabelloRG, cabelloRB,//256
		-2.5f,-4.5f,0.08f, cabelloRR, cabelloRG, cabelloRB,//257
		-2.0f,-5.0f,0.08f, cabelloRR, cabelloRG, cabelloRB,//258
		-1.4f,-5.6f,0.08f, cabelloRR, cabelloRG, cabelloRB,//259
		-2.0f,-5.7f,0.08f, cabelloRR, cabelloRG, cabelloRB,//260
		-3.0f,-5.4f,0.08f, cabelloRR, cabelloRG, cabelloRB,//261
		-4.0f,-5.0f,0.08f, cabelloRR, cabelloRG, cabelloRB,//262
		-4.3f,-4.0f,0.08f, cabelloRR, cabelloRG, cabelloRB,//263
		-4.25f,-3.0f,0.08f, cabelloRR, cabelloRG, cabelloRB,//264
		-4.2f,-2.6f,0.08f, cabelloRR, cabelloRG, cabelloRB,//265
		-4.0f,-4.0f,0.08f, cabelloRR, cabelloRG, cabelloRB,//266

		-7.0f,-0.4f,0.08f, cabelloRR, cabelloRG, cabelloRB,//267
		-6.2f,-1.0f,0.08f, cabelloRR, cabelloRG, cabelloRB,//268
		-6.0f,-1.4f, 0.08f, cabelloRR, cabelloRG, cabelloRB,//269
		-5.8f,-2.0f,0.08f, cabelloRR, cabelloRG, cabelloRB,//270
		-5.7f,-3.0f,0.08f, cabelloRR, cabelloRG, cabelloRB,//271
		-5.7f,-3.5f,0.08f, cabelloRR, cabelloRG, cabelloRB,//272
		-6.0f,-4.0f,0.08f, cabelloRR, cabelloRG, cabelloRB,//273
		-6.2f,-5.0f,0.08f, cabelloRR, cabelloRG, cabelloRB,//274
		-7.0f,-5.4f,0.08f, cabelloRR, cabelloRG, cabelloRB,//275
		-8.0f,-6.0f,0.08f, cabelloRR, cabelloRG, cabelloRB,//276
		-7.6f,-5.0f,0.08f, cabelloRR, cabelloRG, cabelloRB,//277
		-7.2f,-4.0f,0.08f, cabelloRR, cabelloRG, cabelloRB,//278
		-7.0f,-3.0f,0.08f, cabelloRR, cabelloRG, cabelloRB,//279
		-6.0f,-3.0f,0.08f, cabelloRR, cabelloRG, cabelloRB,//280

		//Estrellas Frentes Xayah
		3.4f,0.6f,1.2f, detalleMR,detalleMG,detalleMB,//281
		3.35f,0.9f,1.2f, detalleMR, detalleMG, detalleMB,//282
		3.4f,0.7f, 1.2f, detalleMR, detalleMG, detalleMB,//283
		3.6f,0.5f,1.2f,  detalleMR, detalleMG, detalleMB,//284
		3.4f, 0.4f, 1.2f, detalleMR, detalleMG, detalleMB,//285
		3.35f, 0.0f, 1.2f, detalleMR, detalleMG, detalleMB,//286
		3.2f, 0.4f, 1.2f, detalleMR, detalleMG, detalleMB,//287
		3.0f, 0.5f, 1.2f, detalleMR, detalleMG, detalleMB,//288
		3.2f, 0.6f,1.2f, detalleMR, detalleMG, detalleMB,//289
		//Estrella Frente Rakan

		-3.0f,1.0f,1.2f, detalleMR, detalleMG, detalleMB,//290
		-2.9f,1.8f,1.2f, detalleMR, detalleMG, detalleMB,//291
		-2.7f,1.3f,1.2f, detalleMR, detalleMG, detalleMB,//292
		-2.1f,0.9f,1.2f, detalleMR, detalleMG, detalleMB,//293
		-2.8f,0.7f,1.2f, detalleMR, detalleMG, detalleMB,//294
		-3.1f,0.2f,1.2f, detalleMR, detalleMG, detalleMB,//295
		-3.4f,0.9f,1.2f, detalleMR, detalleMG, detalleMB,//296
		-4.0f,1.2f,1.2f, detalleMR, detalleMG, detalleMB,//297
		-3.2f,1.3f,1.2f, detalleMR, detalleMG, detalleMB,//298

		//Oreja
		-5.0f,-0.4f,1.2f, detalleMR, detalleMG, detalleMB,//299
		-5.2f,0.0f,1.2f, detalleMR, detalleMG, detalleMB,//300
		-5.8f,1.0f,1.2f, detalleMR, detalleMG, detalleMB,//301
		-6.0f,1.5f,1.2f, detalleMR, detalleMG, detalleMB,//302
		-6.2f,2.0f,1.2f, detalleMR, detalleMG, detalleMB,//303
		-7.0f,2.8f,1.2f, detalleMR, detalleMG, detalleMB,//304
		-7.2f,3.0f,1.2f, detalleMR, detalleMG, detalleMB,//305
		-8.0f,4.0f,1.2f, detalleMR, detalleMG, detalleMB,//306
		-9.0f,5.0f,1.2f, detalleMR, detalleMG, detalleMB,//307
		-8.9f,4.0f,1.2f, detalleMR, detalleMG, detalleMB,//308
		-8.8f,3.0f,1.2f, detalleMR, detalleMG, detalleMB,//309
		-8.7f,2.0f,1.2f, detalleMR, detalleMG, detalleMB,//310
		-8.5f,1.0f,1.2f, detalleMR, detalleMG, detalleMB,//311
		-8.0f,0.2f,1.2f, detalleMR, detalleMG, detalleMB,//312
		-7.7f,0.0f,1.2f, detalleMR, detalleMG, detalleMB,//313
		-7.0f,-0.6f,1.2f, detalleMR, detalleMG, detalleMB,//314
		-6.5f,-0.7f,1.2f, detalleMR, detalleMG, detalleMB,//315
		-6.0f,-1.1f,1.2f, detalleMR, detalleMG, detalleMB,//316
		-5.3f,-2.0f,1.2f, detalleMR, detalleMG, detalleMB,//317
		-5.5f,-1.5f,1.2f, detalleMR, detalleMG, detalleMB,//318
		-5.6f,-1.0f,1.2f, detalleMR, detalleMG, detalleMB,//319
		-5.5f,-0.5f,1.2f, detalleMR, detalleMG, detalleMB,//320
		-5.3f,-0.3f,1.2f, detalleMR, detalleMG, detalleMB,//321
		-7.5f,1.5f,1.2f, detalleMR, detalleMG, detalleMB,//322

		//Oreja Interna
		-6.0f,0.0f,1.3f, orejaR,orejaG,orejaB+0.3f,//323
		-6.5f,1.0f,1.3f, orejaR, orejaG, orejaB, //324
		-7.0f,1.5f,1.3f, orejaR, orejaG, orejaB, //325
		-7.3f,2.0f,1.3f, orejaR, orejaG, orejaB, //326
		-8.0f,3.0f,1.3f, orejaR, orejaG, orejaB, //327
		-8.6f,3.9f,1.3f, orejaR, orejaG+0.4f, orejaB, //328
		-8.5f,3.0f,1.3f, orejaR, orejaG, orejaB, //329
		-8.3f,2.0f,1.3f, orejaR, orejaG, orejaB, //330
		-8.0f,1.4f,1.3f, orejaR, orejaG, orejaB, //331
		-7.6f,1.0f,1.3f, orejaR, orejaG, orejaB, //332
		-7.0f,0.5f,1.3f, orejaR, orejaG, orejaB, //333
		-7.5f,1.5f,1.3f, orejaR, orejaG+0.3f, orejaB+0.3f, //334

		//Fondo 
		-5.0f,-6.0f,0.05f, detalleR-0.15f, detalleG-0.05f, detalleB-0.25f,//335
		0.0f,-5.0f,0.05f, detalleR, detalleG, detalleB,//336
		-0.5f,-4.0f,0.05f, detalleR, detalleG, detalleB,//337
		-1.0f,-3.0f,0.05f, detalleR, detalleG, detalleB,//338
		-2.0f,-1.8f,0.05f, detalleR, detalleG, detalleB,//339
		-3.0f,-1.0f,0.05f, detalleR, detalleG, detalleB,//340
		-7.0f,0.0f,0.05f, detalleR, detalleG, detalleB,//341
		-8.0f,0.2f,0.05f, detalleR, detalleG, detalleB,//342
		-10.0f,-1.0f,0.05f, detalleR, detalleG, detalleB,//343

		5.0f,-6.0f,0.05f,  detalleR - 0.15f, detalleG - 0.05f, detalleB - 0.25f,//344
		10.0f,-1.0f,0.05f, detalleR, detalleG, detalleB,//345
		9.0f,0.0f,0.05f, detalleR, detalleG, detalleB,//346
		8.0f,0.2f,0.05f, detalleR, detalleG, detalleB,//347
		7.0f,0.5f,0.05f, detalleR, detalleG, detalleB,//348
		2.0f,-0.5f,0.05f, detalleR, detalleG, detalleB,//349
		1.0f,-0.8f,0.05f, detalleR, detalleG, detalleB,//350
		0.0f,-1.5f,0.05f, detalleR, detalleG, detalleB,//351

		6.0f,-2.5f,0.07f, detalleR1, detalleG1, detalleB1,//352
		4.0f,-2.5f,0.07f, detalleR1, detalleG1, detalleB1,//353
		5.0f,-4.0f,0.07f, detalleR1, detalleG1, detalleB1,//354

		5.0f,-4.5f,0.07f, detalleR1, detalleG1, detalleB1,//355
		5.0f, -4.0f, 0.07f, detalleR1, detalleG1, detalleB1,//356
		5.1f,-4.2f,0.07f, detalleR1, detalleG1, detalleB1,//357
		5.4f,-4.5f,0.07f, detalleR1, detalleG1, detalleB1,//358
		5.0f,-4.8f,0.07f, detalleR1, detalleG1, detalleB1,//359
		4.9f,-5.2f,0.07f, detalleR1, detalleG1, detalleB1,//360
		4.65f,-4.7f,0.07f, detalleR1, detalleG1, detalleB1,//361
		4.4f,-4.5f,0.07f, detalleR1, detalleG1, detalleB1,//362
		4.65f,-4.4f,0.07f, detalleR1, detalleG1, detalleB1,//363

		6.0f,-2.0f,0.06f,1.0f,1.0f,1.0f,//364
		7.0f,-3.0f, 0.06f, 1.0f, 1.0f, 1.0f,//365
		5.0f,-6.0f,0.06f,1.0f, 1.0f, 1.0f,//366
		3.0f,-4.0f,0.06f, 1.0f, 1.0f, 1.0f,//367

		//Dorado
		4.8f,3.6f,0.09f,doradoR,doradoG,doradoB,//368
		5.8f,4.8f,0.09f, doradoR, doradoG, doradoB,//369
		4.5f,5.0f,0.09f, doradoR, doradoG, doradoB,//370

		5.0f,3.4f,0.09f, doradoR, doradoG, doradoB,//371
		5.0f,3.7f,0.09f, doradoR, doradoG, doradoB,//372
		7.3f,4.6f,0.09f, doradoR, doradoG, doradoB,//373
		7.3f,4.3f,0.09f, doradoR, doradoG, doradoB,//374

		3.9f,3.5f,0.09f, doradoR, doradoG, doradoB,//375
		3.3f,4.6f,0.09f, doradoR, doradoG, doradoB,//376
		2.9f,3.5f,0.09f, doradoR, doradoG, doradoB,//377
		3.1f,3.0f,0.09f, doradoR, doradoG, doradoB,//378

		2.6f,2.5f,0.09f, doradoR, doradoG, doradoB,//379
		2.6f,2.8f,0.09f, doradoR, doradoG, doradoB,//380
		1.0f,3.4f,0.09f, doradoR, doradoG, doradoB,//381
		1.0f,3.1f,0.09f, doradoR, doradoG, doradoB,//382

		//orejas xayah
		7.5f,1.2f,0.04f,orejasR,orejasG,orejasB,//383
		8.0f,3.0f,0.04f, orejasR, orejasG, orejasB,//384
		7.5f,2.9f,0.04f, orejasR, orejasG, orejasB,//385
		6.0f,1.0f,0.04f, orejasR, orejasG, orejasB,//386

		7.0f,2.0f,0.04f, orejasR, orejasG, orejasB,//387
		7.4f,3.0f,0.04f, orejasR, orejasG, orejasB,//388
		7.7f,4.0f,0.04f, orejasR, orejasG, orejasB,//389
		7.0f,3.6f,0.04f, orejasR, orejasG, orejasB,//390
		6.0f,1.0f,0.04f, orejasR, orejasG, orejasB,//391

		7.0f,3.0f,0.04f, orejasR, orejasG, orejasB,//392
		7.3f,5.0f,0.04f, orejasR, orejasG, orejasB,//393
		6.8f,4.5f,0.04f, orejasR, orejasG, orejasB,//394
		6.0f,6.0f,0.04f, orejasR, orejasG, orejasB,//395
		4.4f,6.6f,0.04f, orejasR, orejasG, orejasB,//396
		5.5f,2.0f,0.04f, orejasR, orejasG, orejasB,//397

		1.5f,1.4f,0.04f, orejasR, orejasG, orejasB,//398
		1.0f,3.1f,0.04f, orejasR, orejasG, orejasB,//399
		1.7f,5.5f,0.04f, orejasR, orejasG, orejasB,//400
		1.9f,5.0f,0.04f, orejasR, orejasG, orejasB,//401
		2.2f,6.5f,0.04f, orejasR, orejasG, orejasB,//402
		3.5f,1.0f,0.04f, orejasR, orejasG, orejasB,//403

		-5.5f,4.0f,0.1f, pielR, pielG, pielB,//404
		-6.0f,3.5f,0.1f, pielR, pielG, pielB,//405
		-6.0f,3.0f,0.1f, pielR, pielG, pielB,//406
		-7.0f,2.0f,0.1f, pielR, pielG, pielB,//407
		-6.0f,1.0f,0.1f, pielR, pielG, pielB,//408
		-4.0f,3.0f,0.1f, pielR, pielG, pielB,//409

		-4.0f,-2.0f,0.095f, orejaR, orejaG, orejaB,//410
		-3.9f,-2.8f,0.095f, orejaR, orejaG, orejaB,//411
		-4.0f,-2.9f, 0.095f, orejaR, orejaG, orejaB,//412
		-4.6f,-2.9f,0.095f, orejaR, orejaG, orejaB,//413
		-4.8f,-2.6f,0.095f, orejaR, orejaG, orejaB,//414

			//Oreja Trasera
		0.0f,3.6f,0.04f, detalleMR, detalleMG, detalleMB,//415
		-1.0f,1.5f,0.04f, detalleMR, detalleMG, detalleMB,//416
		-2.5f,0.5f,0.04f, detalleMR, detalleMG, detalleMB,//417
		-2.5f,2.0f,0.04f, detalleMR, detalleMG, detalleMB,//418

		3.3f,1.8f,0.26f, orejasR, orejasG, orejasB,//419
		3.0f,2.0f,0.26f, orejasR, orejasG, orejasB,//420
		2.7f,1.5f,0.26f, orejasR, orejasG, orejasB,//421
		2.5f, 0.5f, 0.26f, orejasR, orejasG, orejasB,//422
		2.7f,0.0f,0.26f, orejasR, orejasG, orejasB,//423
		3.0f,-0.5f,0.26f, orejasR, orejasG, orejasB,//424
		3.3f,-0.7f,0.26f, orejasR, orejasG, orejasB,//425
		3.0f,0.0f,0.26f, orejasR, orejasG, orejasB,//426
		2.9f,0.5f,0.26f, orejasR, orejasG, orejasB,//427
		3.0f,1.0f,0.26f, orejasR, orejasG, orejasB,//428
		2.8f,0.5f,0.26f, orejasR, orejasG, orejasB,//429

		6.3f,0.0f,0.24f, orejasR, orejasG, orejasB,//430
		6.0f,-0.5f,0.24f, orejasR, orejasG, orejasB,//431
		5.9f,-1.0f,0.24f, orejasR, orejasG, orejasB,//432
		5.8f,-2.0f,0.24f, orejasR, orejasG, orejasB,//433
		5.7f,-3.0f,0.24f, orejasR, orejasG, orejasB,//434
		5.7f,-4.0f,0.24f, orejasR, orejasG, orejasB,//435
		6.0f,-5.0f,0.24f, orejasR, orejasG, orejasB,//436
		6.3f,-5.3f,0.24f, orejasR, orejasG, orejasB,//437
		6.0f,-4.0f,0.24f, orejasR, orejasG, orejasB,//438
		6.1f,-3.0f,0.24f, orejasR, orejasG, orejasB,//439
		6.2f,-2.0f,0.24f, orejasR, orejasG, orejasB,//440
		6.3f,-1.0f,0.24f, orejasR, orejasG, orejasB,//441
		5.85f,-3.5f,0.24f, orejasR, orejasG, orejasB,//442

		//ojos Xayah
		4.2f,-0.1f,1.0f,1.0f,1.0f,1.0f,//443
		4.7f,-0.1f,1.0f, 1.0f, 1.0f, 1.0f,//444
		5.0f,0.0f,1.0f, 1.0f, 1.0f, 1.0f,//445
		5.1f,0.2f,1.0f, 1.0f, 1.0f, 1.0f,//446
		5.2f,0.6f,1.0f , 1.0f, 1.0f, 1.0f,//447
		5.0f,0.6f,1.0f, 1.0f, 1.0f, 1.0f,//448
		4.9f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f,//449
		4.6f,0.4f,1.0f, 1.0f, 1.0f, 1.0f,//450
		4.4f,0.2f,1.0f, 1.0f, 1.0f, 1.0f,//451


		4.7f, -0.1f, 1.1f, ojosXR,ojosXG,ojosXB, //452
		5.0f,0.0f,1.1f, ojosXR, ojosXG, ojosXB, //453
		5.1f,0.1f,1.1f, ojosXR, ojosXG, ojosXB, //454
		5.0f,0.5f,1.1f, ojosXR, ojosXG, ojosXB, //455
		4.9f,0.5f,1.1f, ojosXR, ojosXG, ojosXB, //456
		4.6f,0.4f,1.1f, ojosXR, ojosXG, ojosXB, //457
		4.55f,0.2f,1.1f, ojosXR, ojosXG, ojosXB, //458
		4.9f,0.3f,1.1f, ojosXR, ojosXG, ojosXB, //459

		4.8f,0.05f,1.2f,0.0f,0.0f,0.0f,//460
		4.9f, 0.45f, 1.2f, 0.0f, 0.0f, 0.0f,//461
		4.7f,0.35f,1.2f, 0.0f, 0.0f, 0.0f,//462

		4.15f,-0.1f,1.3f, 0.3f, 0.0f, 0.2f,//463
		4.3f,0.0f,1.3f, 0.3f, 0.0f, 0.2f,//464
		5.0f,0.4f,1.3f, 0.3f, 0.0f, 0.2f,//465
		5.4f,0.6f,1.3f, 0.3f, 0.0f, 0.2f,//466
		5.0f,0.55f,1.3f, 0.3f, 0.0f, 0.2f,//467
		4.5f,0.5f,1.3f, 0.3f, 0.0f, 0.2f,//468
		4.2f,0.2f,1.3f, 0.3f, 0.0f, 0.2f,//469
		4.6f,0.4f,1.3f, 0.3f, 0.0f, 0.2f,//470

		//Ceja
		4.0f,0.0f, 1.3f, 0.3f, 0.0f, 0.2f,//471
		4.1f,0.4f, 1.3f, 0.3f, 0.0f, 0.2f,//472
		4.8f,1.0f, 1.3f, 0.3f, 0.0f, 0.2f,//473
		5.3f,0.9f, 1.3f, 0.3f, 0.0f, 0.2f,//474
		4.8f,0.9f, 1.3f, 0.3f, 0.0f, 0.2f,//475

		//ojos Rakan
		-5.2f,0.9f, 1.0f, 1.0f, 1.0f, 1.0f,//476
		-5.0f,0.5f, 1.0f, 1.0f, 1.0f, 1.0f,//477
		-4.4f,0.3f, 1.0f, 1.0f, 1.0f, 1.0f,//478
		-4.0f,0.55f, 1.0f, 1.0f, 1.0f, 1.0f,//479

		-3.0f,0.0f, 1.0f, 1.0f, 1.0f, 1.0f,//480
		-2.7f,-0.3f, 1.0f, 1.0f, 1.0f, 1.0f,//481
		-2.4f,0.0f , 1.0f, 1.0f, 1.0f, 1.0f,//482
		-2.4f,0.2f, 1.0f, 1.0f, 1.0f, 1.0f,//483
		-2.8f,0.2f, 1.0f, 1.0f, 1.0f, 1.0f,//484

		-4.8f,0.8f,1.1f, doradoR, doradoG, doradoB,//485
		-4.75f,0.4f, 1.1f, doradoR, doradoG, doradoB,//486
		-4.4f,0.3f, 1.1f, doradoR, doradoG, doradoB,//487
		-4.3f,0.65f, 1.1f, doradoR, doradoG, doradoB,//488
		-4.6f,0.6f, 1.1f, doradoR, doradoG, doradoB,//489

		-3.0f,0.0f, 1.1f, doradoR, doradoG, doradoB,//490
		-2.7f,-0.3f, 1.1f, doradoR, doradoG, doradoB,//491
		-2.5f,0.0f, 1.1f, doradoR, doradoG, doradoB,//492
		-2.45f,0.3f, 1.1f, doradoR, doradoG, doradoB,//493
		-2.8f,0.3f, 1.1f, doradoR, doradoG, doradoB,//494

		-5.3f,1.1f,1.3f,0.0f,0.2f,0.1f,//495
		-4.0f,0.5f, 1.3f, 0.0f, 0.2f, 0.1f,//496
		-5.2f,0.8f, 1.3f, 0.0f, 0.2f, 0.1f,//497

		-4.0f,0.5f,1.4f, detalleMR, detalleMG, detalleMB,//498
		-3.7f,0.7f,1.4f , detalleMR, detalleMG, detalleMB,//499
		-4.7f,1.5f,1.4f, detalleMR, detalleMG, detalleMB,//500
		-5.5f,1.0f,1.4f, detalleMR, detalleMG, detalleMB,//501
		-4.9f,1.2f,1.4f, detalleMR, detalleMG, detalleMB,//502

		-2.9f,0.3f, 1.4f, detalleMR, detalleMG, detalleMB,//503
		-3.1f,0.0f, 1.4f, detalleMR, detalleMG, detalleMB,//504
		-2.1f,0.35f, 1.4f, detalleMR, detalleMG, detalleMB,//505
		-2.0f,0.5f, 1.4f, detalleMR, detalleMG, detalleMB,//506

		-4.6f,0.4f,1.3f,0.0f,0.0f,0.0f,//507
		-4.4f,0.7f, 1.3f, 0.0f, 0.0f, 0.0f,//508
		-4.7f,0.8f, 1.3f, 0.0f, 0.0f, 0.0f,//509

		-2.75f,-0.2f, 1.3f, 0.0f, 0.0f, 0.0f,//510
		-2.6f,0.2f, 1.3f, 0.0f, 0.0f, 0.0f,//511
		-2.8f,0.2f, 1.3f, 0.0f, 0.0f, 0.0f,//512

		//labios
		4.7f,-1.7f, 1.3f, cabelloXR, cabelloXG, cabelloXB,//513
		4.1f,-1.5f, 1.3f, cabelloXR, cabelloXG, cabelloXB,//514
		3.9f,-1.5f, 1.3f, cabelloXR, cabelloXG, cabelloXB,//515
		3.7f,-1.7f, 1.3f, cabelloXR, cabelloXG, cabelloXB,//516
		3.85f,-1.85f, 1.3f, cabelloXR, cabelloXG, cabelloXB,//517
		3.8f,-2.0f, 1.3f, cabelloXR, cabelloXG, cabelloXB,//518
		4.0f,-2.1f, 1.3f, cabelloXR, cabelloXG, cabelloXB,//519
		4.1f,-2.1f, 1.3f, cabelloXR, cabelloXG, cabelloXB,//520
		4.0f,-1.95f, 1.3f, cabelloXR, cabelloXG, cabelloXB,//521

		//sombras
		3.0f,-1.0f,0.15f,sombrasR,sombrasG,sombrasB,//522
		3.0f,0.0f, 0.15f, sombrasR, sombrasG, sombrasB,//523
		3.5f,-0.5f, 0.15f, sombrasR, sombrasG, sombrasB,//524
		3.5f,-1.0f,0.15f, sombrasR, sombrasG, sombrasB,//525
		3.7f,-1.2f,0.15f, sombrasR, sombrasG, sombrasB,//526
		3.8f,-1.4f, 0.15f, sombrasR, sombrasG, sombrasB,//527

		5.6f,-1.2f,0.095f, sombrasR, sombrasG, sombrasB,//528
		4.9f,-3.0f,0.095f,sombrasR, sombrasG, sombrasB,//529
		4.45f,-2.5f,0.095f, sombrasR, sombrasG, sombrasB,//530

		-3.1f,0.0f, 0.15f, sombrasR, sombrasG, sombrasB,//531
		-3.0f,-1.1f, 0.15f, sombrasR, sombrasG, sombrasB,//532
		-3.5f,-1.5f, 0.15f, sombrasR, sombrasG, sombrasB,//533
		-3.4f,-1.2f, 0.15f, sombrasR, sombrasG, sombrasB,//534
		-3.5f,-0.8f, 0.15f, sombrasR, sombrasG, sombrasB,//535

		-5.0f,-1.2f, 0.15f, sombrasR, sombrasG, sombrasB,//536
		-4.0f,-1.7f, 0.15f, sombrasR, sombrasG, sombrasB,//537
		-3.5f,-1.7f, 0.15f, sombrasR, sombrasG, sombrasB,//538
		-4.0f, -1.69f, 0.15f, sombrasR, sombrasG, sombrasB,//539

		-1.8f,3.0f, 0.15f, sombrasR, sombrasG, sombrasB,//540
		-2.0f,0.4f, 0.15f, sombrasR, sombrasG, sombrasB,//541
		-2.5f,3.0f, 0.15f, sombrasR, sombrasG, sombrasB,//542g

		4.0f,-1.2f, 0.15f, sombrasR, sombrasG, sombrasB,//543
		4.05f,-1.15f, 0.15f, sombrasR, sombrasG, sombrasB,//544
		-4.0f,-1.2f, 0.15f, sombrasR, sombrasG, sombrasB,//545
		-3.7f,-1.3f, 0.15f, sombrasR, sombrasG, sombrasB,//546

		-4.0f,-2.5f,0.095f, sombrasR, sombrasG, sombrasB,//547
		-4.6f,-4.0f, 0.095f, sombrasR, sombrasG, sombrasB,//548
		-5.6f,-1.5f, 0.095f, sombrasR, sombrasG, sombrasB,//549


		//Lineas cabello Xayah

		3.4f,2.0f,0.26f,lineasCabelloXR,lineasCabelloXG,lineasCabelloXB,//550
		3.7f,2.4f,0.26f , lineasCabelloXR, lineasCabelloXG, lineasCabelloXB,//551
		4.0f,2.6f, 0.26f, lineasCabelloXR, lineasCabelloXG, lineasCabelloXB,//552
		4.5f,2.8f, 0.26f, lineasCabelloXR, lineasCabelloXG, lineasCabelloXB,//553
		5.0f,2.6f, 0.26f, lineasCabelloXR, lineasCabelloXG, lineasCabelloXB,//554
		5.3f,2.3f, 0.26f, lineasCabelloXR, lineasCabelloXG, lineasCabelloXB,//555
		5.6f,2.0f, 0.26f, lineasCabelloXR, lineasCabelloXG, lineasCabelloXB,//556
		6.0f,1.8f, 0.26f, lineasCabelloXR, lineasCabelloXG, lineasCabelloXB,//557
		6.3f,2.0f, 0.26f, lineasCabelloXR, lineasCabelloXG, lineasCabelloXB,//558
		6.45f,2.2f, 0.26f, lineasCabelloXR, lineasCabelloXG, lineasCabelloXB,//559
		6.45f,2.5f, 0.26f, lineasCabelloXR, lineasCabelloXG, lineasCabelloXB,//560
		6.6f,2.2f, 0.26f, lineasCabelloXR, lineasCabelloXG, lineasCabelloXB,//561
		6.7f,2.0f, 0.26f, lineasCabelloXR, lineasCabelloXG, lineasCabelloXB,//562
		6.6f,1.7f, 0.26f, lineasCabelloXR, lineasCabelloXG, lineasCabelloXB,//563
		6.2f,1.0f, 0.26f, lineasCabelloXR, lineasCabelloXG, lineasCabelloXB,//564
		5.9f,1.0f, 0.26f, lineasCabelloXR, lineasCabelloXG, lineasCabelloXB,//565

		7.2f,0.5f, 0.26f, lineasCabelloXR, lineasCabelloXG, lineasCabelloXB,//566
		7.0f,-0.2f, 0.26f, lineasCabelloXR, lineasCabelloXG, lineasCabelloXB,//567
		6.7f,-1.0f, 0.26f, lineasCabelloXR, lineasCabelloXG, lineasCabelloXB,//568
		6.3f,-2.0f, 0.26f, lineasCabelloXR, lineasCabelloXG, lineasCabelloXB,//569

		3.6f,2.5f, 0.26f, lineasCabelloXR, lineasCabelloXG, lineasCabelloXB,//570
		4.0f,3.5f, 0.26f, lineasCabelloXR, lineasCabelloXG, lineasCabelloXB,//571
		4.3f,3.6f, 0.26f, lineasCabelloXR, lineasCabelloXG, lineasCabelloXB,//572

		3.3f,2.0f, 0.26f, lineasCabelloXR, lineasCabelloXG, lineasCabelloXB,//573
		3.0f,2.8f, 0.26f, lineasCabelloXR, lineasCabelloXG, lineasCabelloXB,//574
		2.5f,2.5f, 0.26f, lineasCabelloXR, lineasCabelloXG, lineasCabelloXB,//575
		2.9f,2.4f, 0.26f, lineasCabelloXR, lineasCabelloXG, lineasCabelloXB,//576

		4.0f,-3.0f, 0.26f, lineasCabelloXR, lineasCabelloXG, lineasCabelloXB,//577
		3.8f,-4.0f, 0.26f, lineasCabelloXR, lineasCabelloXG, lineasCabelloXB,//578
		3.3f,-4.8f, 0.26f, lineasCabelloXR, lineasCabelloXG, lineasCabelloXB,//579

		//LINEAS Cabello Rakan
		-5.9f,-2.3f, 0.09f, lineasCabelloRR, lineasCabelloRG, lineasCabelloRB,//580
		-6.0f,-0.9f, 0.09f, lineasCabelloRR, lineasCabelloRG, lineasCabelloRB,//581
		-7.0f,0.0f , 0.09f, lineasCabelloRR, lineasCabelloRG, lineasCabelloRB,//582

		-3.2f,-1.8f, 0.09f, lineasCabelloRR, lineasCabelloRG, lineasCabelloRB,//583
		-3.5f,-4.0f, 0.09f, lineasCabelloRR, lineasCabelloRG, lineasCabelloRB,//584
		-4.0f,-1.8f, 0.09f, lineasCabelloRR, lineasCabelloRG, lineasCabelloRB,//585

		-2.5f,2.1f, 0.16f, lineasCabelloRR, lineasCabelloRG, lineasCabelloRB,//586
		-2.0f,2.2f, 0.16f, lineasCabelloRR, lineasCabelloRG, lineasCabelloRB,//587
		-1.8f,2.0f, 0.16f, lineasCabelloRR, lineasCabelloRG, lineasCabelloRB,//588
		-1.6f,1.5f, 0.16f, lineasCabelloRR, lineasCabelloRG, lineasCabelloRB,//589
		-1.5f,1.0f, 0.16f, lineasCabelloRR, lineasCabelloRG, lineasCabelloRB,//590
		-1.5f,0.0f, 0.16f, lineasCabelloRR, lineasCabelloRG, lineasCabelloRB,//591
		-2.0f,1.0f, 0.16f, lineasCabelloRR, lineasCabelloRG, lineasCabelloRB,//592
		-2.2f,1.6f, 0.16f, lineasCabelloRR, lineasCabelloRG, lineasCabelloRB,//593
		
		-3.0f,2.0f, 0.26f, lineasCabelloRR, lineasCabelloRG, lineasCabelloRB,//594
		-2.1f,2.6f, 0.26f, lineasCabelloRR, lineasCabelloRG, lineasCabelloRB,//595
		-2.5f,2.8f, 0.26f, lineasCabelloRR, lineasCabelloRG, lineasCabelloRB,//596
		-2.9f,2.6f, 0.26f, lineasCabelloRR, lineasCabelloRG, lineasCabelloRB,//597
		-3.3f,2.8f, 0.26f, lineasCabelloRR, lineasCabelloRG, lineasCabelloRB,//598
		-3.6f,2.3f, 0.26f, lineasCabelloRR, lineasCabelloRG, lineasCabelloRB,//599

		-5.6f,2.4f, 0.26f, lineasCabelloRR, lineasCabelloRG, lineasCabelloRB,//600
		-6.0f,2.7f, 0.26f, lineasCabelloRR, lineasCabelloRG, lineasCabelloRB,//601
		-6.3f,3.0f, 0.26f, lineasCabelloRR, lineasCabelloRG, lineasCabelloRB,//602
		-6.5f,3.3f, 0.26f, lineasCabelloRR, lineasCabelloRG, lineasCabelloRB,//603
		-6.5f,2.8f, 0.26f, lineasCabelloRR, lineasCabelloRG, lineasCabelloRB,//604
		-6.0f,2.2f, 0.26f, lineasCabelloRR, lineasCabelloRG, lineasCabelloRB,//605
		-6.2f,2.6f, 0.26f, lineasCabelloRR, lineasCabelloRG, lineasCabelloRB,//606

		-5.1f,2.9f, 0.26f, lineasCabelloRR, lineasCabelloRG, lineasCabelloRB,//607
		-5.2f,3.6f, 0.26f, lineasCabelloRR, lineasCabelloRG, lineasCabelloRB,//608
		-5.7f,4.1f, 0.26f, lineasCabelloRR, lineasCabelloRG, lineasCabelloRB,//609
		-5.8f,3.6f, 0.26f, lineasCabelloRR, lineasCabelloRG, lineasCabelloRB,//610
		-5.5f,3.6f, 0.26f, lineasCabelloRR, lineasCabelloRG, lineasCabelloRB,//611

		-4.4f,4.0f, 0.26f, lineasCabelloRR, lineasCabelloRG, lineasCabelloRB,//612
		-4.0f,3.5f, 0.26f, lineasCabelloRR, lineasCabelloRG, lineasCabelloRB,//613
		-3.7f,3.0f, 0.26f, lineasCabelloRR, lineasCabelloRG, lineasCabelloRB,//614

		-2.1f,3.0f, 0.26f, lineasCabelloRR, lineasCabelloRG, lineasCabelloRB,//615
		-2.0f,3.2f, 0.26f, lineasCabelloRR, lineasCabelloRG, lineasCabelloRB,//616
		-2.1f,3.4f, 0.26f, lineasCabelloRR, lineasCabelloRG, lineasCabelloRB,//617
		-2.2f,3.6f, 0.26f, lineasCabelloRR, lineasCabelloRG, lineasCabelloRB,//618

		-6.7f,-2.0f, 0.26f, lineasCabelloRR, lineasCabelloRG, lineasCabelloRB,//619
		-6.6f,-3.0f, 0.26f, lineasCabelloRR, lineasCabelloRG, lineasCabelloRB,//620
		-6.7f,-3.5f, 0.26f, lineasCabelloRR, lineasCabelloRG, lineasCabelloRB,//621
		-6.8f,-4.0f, 0.26f, lineasCabelloRR, lineasCabelloRG, lineasCabelloRB,//622

		-1.0f,0.0f, 0.26f, lineasCabelloRR, lineasCabelloRG, lineasCabelloRB,//623
		-0.8f,-0.5f, 0.26f, lineasCabelloRR, lineasCabelloRG, lineasCabelloRB,//624
		-1.2f,-1.2f, 0.26f, lineasCabelloRR, lineasCabelloRG, lineasCabelloRB,//625
		-1.0f,-0.5f, 0.26f, lineasCabelloRR, lineasCabelloRG, lineasCabelloRB,//626

		//detalles Xayah
		1.8f,0.5f, 0.26f, lineasCabelloXR, lineasCabelloXG, lineasCabelloXB,//627
		2.0f,1.0f, 0.26f, lineasCabelloXR, lineasCabelloXG, lineasCabelloXB,//628
		2.1f,1.2f, 0.26f, lineasCabelloXR, lineasCabelloXG, lineasCabelloXB,//629
		2.1f,0.5f, 0.26f, lineasCabelloXR, lineasCabelloXG, lineasCabelloXB,//630
		2.2f,0.0f, 0.26f, lineasCabelloXR, lineasCabelloXG, lineasCabelloXB,//631
		2.4f,-0.4f, 0.26f, lineasCabelloXR, lineasCabelloXG, lineasCabelloXB,//632

		4.5f,3.0f, 0.26f, lineasCabelloXR, lineasCabelloXG, lineasCabelloXB,//633
		5.0f,3.2f, 0.26f, lineasCabelloXR, lineasCabelloXG, lineasCabelloXB,//634
		5.5f,3.3f, 0.26f, lineasCabelloXR, lineasCabelloXG, lineasCabelloXB,//635
		6.0f,2.7f, 0.26f, lineasCabelloXR, lineasCabelloXG, lineasCabelloXB,//636
		5.0f,3.0f, 0.26f, lineasCabelloXR, lineasCabelloXG, lineasCabelloXB,//637

		6.3f,-2.5f, 0.26f, lineasCabelloXR, lineasCabelloXG, lineasCabelloXB,//638
		6.6f,-3.5f, 0.26f, lineasCabelloXR, lineasCabelloXG, lineasCabelloXB,//639
		6.4f,-4.5f, 0.26f, lineasCabelloXR, lineasCabelloXG, lineasCabelloXB,//640

		//luces
		-1.3f,3.0f,0.26f,1.0f,1.0f,1.0f,//641
		-1.0f,2.5f, 0.26f, 1.0f, 1.0f, 1.0f,//642
		-0.8f,2.0f, 0.26f, 1.0f, 1.0f, 1.0f,//643
		-0.5f, 1.5f, 0.26f, 1.0f, 1.0f, 1.0f,//644
		-0.4f, 1.0f, 0.26f, 1.0f, 1.0f, 1.0f,//645
		-1.4f,2.4f,	0.26f, 0.3f, 1.0f, 1.0f,//646

		-1.7f,2.8f, 0.26f, 1.0f, 1.0f, 1.0f,//647
		-1.9f,4.0f, 0.26f, 0.3f, 1.0f, 1.0f,//648
		-1.4f,3.0f, 0.26f, 1.0f, 1.0f, 1.0f,//649

		2.5f,2.4f, 0.26f, 1.0f, 0.3f, 1.0f,//650
		2.0f,1.2f, 0.26f, 1.0f, 1.0f, 1.0f,//651
		2.0f,2.1f, 0.26f, 1.0f, 1.0f, 1.0f,//652
			
		3.5f,-3.5f, 0.26f, 1.0f, 1.0f, 1.0f,//653
		3.6f,-4.0f, 0.26f, 1.0f, 0.3f, 1.0f,//654
		3.0f,-4.5f, 0.26f, 1.0f, 1.0f, 1.0f,//655
		
	};

	unsigned int indices[] =	
	{
		6,1,2,3,4,7,1,
		7,0,1,6,4,5,0,//Indice 7

		19,8,9,10,11,12,13,14,15,16,17,18,8,						//indice 14
		24,20,21,22,23,24,20,										//indice 27
		37,25,26,27,28,29,30,31,32,33,34,35,36,25,					//indice 34
		41,38,39,40,38,												//indice 48
		55,42,43,44,45,46,47,48,49,50,51,52,53,54,42,				//indice 53
		63,56,57,58,59,60,61,62,56,									//indice 68
		70,64,65,66,67,68,69,64,									//indice 77
		79,71,72,73,74,75,76,77,78,71,								//indice 85
		89,80,81,82,83,84,85,86,87,88,80,							//indice 95
		100,90,91,92,93,94,95,96,97,98,99,90,						//indice 106
		120,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,101,			//indice	118
		129,121,122,123,124,125,126,127,128,121,						//indice 139
		138,130,131,132,133,134,135,136,137,130,							//indice 149
		155,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,139,//indice 159
		165,156,157,158,159,160,161,162,163,164,156,					//indice 177
		166,167,168,169,170,171,172,173,174,167,							//indice 188
		176,177,178,179,180,181,182,183,184,185,186,187,188,176,		//indice 198
		189,190,191,													//indice 212
		192,193,194,195,												//indice 215
		200,196,197,198,199,											//indice 219
		213,201,202,203,204,205,206,207,208,209,210,211,212,201,		//indice 224
		214,215,216,217,218,219,220,221,222,223,						//indice 238
		224,225,226,227,228,229,230,									//indice 248
		231,232,233,234,235,236,237,238,239,240,241,242,				//indice 255
		243,244,245,246,247,248,249,250,251,252,253,					//indice 267
		266,254,255,256,257,258,259,260,261,262,263,264,265,254,		//indice 278
		280,267,268,269,270,271,272,273,274,275,276,277,278,279,267,	//indice 292
		281,282,283,284,285,286,287,288,289,282,						//indice 307
		290,291,292,293,294,295,296,297,298,291,						//indice 317
		322,299,300,301,302,303,304,305,306,307,308,309,310,311,312,313,314,315,316,317,318,319,320,321,299,	//indice 327
		334,323,324,325,326,327,328,329,330,331,332,333,323,			//indices 352
		335,336,337,338,339,340,341,342,343,							//indice 365
		344,345,345,346,347,348,349,350,351,							//indice 374
		352,353,354,													//indice 383
		355,356,357,358,359,360,361,362,363,356,						//indice 386
		364,365,366,367,													//indice 396
		368,369,370,													//indice 400
		371,372,373,374,												//indice 403
		375,376,377,378,												//indice 407
		379,380,381,382,												//indice 411
		386,383,384,385,					//indice415
		391,387,388,389,390,				//indices 419
		397,392,393,394,395,396,			//indices 424
		403,398,399,400,401,402,			//indice 430
		409,404,405,406,407,408,			//indice 436
		410,411,412,413,414,				//indices 442
		415,416,417,418,					//indice 447
		429,419,420,421,422,423,424,425,426,427,428,419,	//451
		442,430,431,432,433,434,435,436,437,438,439,440,441,430,	//463
		443,444,445,446,447,448,449,450,451,//477
		459,452,453,454,455,456,457,458,452,	//486
		460,461,462,							//495
		470,463,464,465,466,467,468,469,463,	//498
		473,472,471,475,474,					//507
		479,476,477,478,						//512
		480,481,482,483,484,					//516
		489,485,486,487,488,485,				//521
		490,491,492,493,494,					//527
		495,496,497,							//532
		500,499,498,502,501,					//535
		503,504,505,506,						//540
		507,508,509,							//544
		510,511,512,							//547
		521,513,514,515,516,517,518,519,520,513,	//550
		522,523,524,525,526,527,				//560
		528,529,530,							//566
		532,533,534,535,531,					//569
		537,536,538,539,						//574
		540,541,542,							//578
		543,544,545,546,						//581
		547,548,549,								//585
		550,551,552,553,554,555,556,557,558,559,560,561,562,563,564,565,//588
		566,567,568,569,							//604
		570,571,572,								//608
		574,575,576,573,							//611
		577,578,579,								//615
		581,580,582,								//618
		583,584,585,								//621
		586,587,588,589,590,591,592,593,			//624
		594,595,596,597,598,599,					//632
		606,600,601,602,603,604,605,600,			//638
		611,607,608,609,610,607,					//646
		612,613,614,								//652
		615,616,617,618,							//655
		619,620,621,622,							//659
		624,623,626,625,							//663
		627,628,629,630,631,632,					//667
		635,636,637,633,634,						//673
		638,639,640,								//678
		646,641,642,643,644,645,					//681
		647,648,649,								//687
		650,651,652,								//690
		653,654,655,								//693
		//696
	};


	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	//Para trabajar con indices (Element Buffer Object)
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

}

void display(Shader shader)
{

	shader.use();

	glm::mat4 model = glm::mat4(1.0f);		// initialize Matrix, Use this matrix for individual models
	glm::mat4 view = glm::mat4(1.0f);		//Use this matrix for ALL models
	glm::mat4 projection = glm::mat4(1.0f);	//This matrix is for Projection

	//Use "projection" in order to change how we see the information
	//projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);

	projection = glm::ortho(-20.0f, 20.0f, -10.0f, 10.0f, -1.5f, 10.0f);

	view = glm::translate(view, glm::vec3(movX, movY, movZ));
	shader.setMat4("model", model);
	shader.setMat4("view", view);
	// note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
	shader.setMat4("projection", projection);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

	//Fondo
	glDrawElements(GL_TRIANGLE_FAN, 7, GL_UNSIGNED_INT, 0);
	//Piel
	glDrawElements(GL_TRIANGLE_FAN, 7, GL_UNSIGNED_INT, (void*)(7 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 13, GL_UNSIGNED_INT, (void*)(14 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 7, GL_UNSIGNED_INT, (void*)(27 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 14, GL_UNSIGNED_INT, (void*)(34 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 5, GL_UNSIGNED_INT, (void*)(48 * sizeof(float)));
	//Cabello
	glDrawElements(GL_TRIANGLE_FAN, 15, GL_UNSIGNED_INT, (void*)(53 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 9, GL_UNSIGNED_INT, (void*)(68 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 8, GL_UNSIGNED_INT, (void*)(77 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 10, GL_UNSIGNED_INT, (void*)(85 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 11, GL_UNSIGNED_INT, (void*)(95 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 12, GL_UNSIGNED_INT, (void*)(106 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 21, GL_UNSIGNED_INT, (void*)(118 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 10, GL_UNSIGNED_INT, (void*)(139 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 10, GL_UNSIGNED_INT, (void*)(149 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 18, GL_UNSIGNED_INT, (void*)(159 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 11, GL_UNSIGNED_INT, (void*)(177 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 10, GL_UNSIGNED_INT, (void*)(188 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 14, GL_UNSIGNED_INT, (void*)(198 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 3, GL_UNSIGNED_INT, (void*)(212 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 4, GL_UNSIGNED_INT, (void*)(215 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 5, GL_UNSIGNED_INT, (void*)(219 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 14, GL_UNSIGNED_INT, (void*)(224 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 10, GL_UNSIGNED_INT, (void*)(238 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 7, GL_UNSIGNED_INT, (void*)(248 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 12, GL_UNSIGNED_INT, (void*)(255 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 11, GL_UNSIGNED_INT, (void*)(267 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 14, GL_UNSIGNED_INT, (void*)(278 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 15, GL_UNSIGNED_INT, (void*)(292 * sizeof(float)));

	//Detalles estrellas
	glDrawElements(GL_TRIANGLE_FAN, 10, GL_UNSIGNED_INT, (void*)(307 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 10, GL_UNSIGNED_INT, (void*)(317 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 25, GL_UNSIGNED_INT, (void*)(327 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 13, GL_UNSIGNED_INT, (void*)(352 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 9, GL_UNSIGNED_INT, (void*)(365 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 9, GL_UNSIGNED_INT, (void*)(374 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 3, GL_UNSIGNED_INT, (void*)(383 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 10, GL_UNSIGNED_INT, (void*)(386 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 4, GL_UNSIGNED_INT, (void*)(396 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 3, GL_UNSIGNED_INT, (void*)(400 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 4, GL_UNSIGNED_INT, (void*)(403 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 4, GL_UNSIGNED_INT, (void*)(407 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 4, GL_UNSIGNED_INT, (void*)(411 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 4, GL_UNSIGNED_INT, (void*)(415 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 5, GL_UNSIGNED_INT, (void*)(419 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 6, GL_UNSIGNED_INT, (void*)(424 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 6, GL_UNSIGNED_INT, (void*)(430 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 6, GL_UNSIGNED_INT, (void*)(436 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 5, GL_UNSIGNED_INT, (void*)(442 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 4, GL_UNSIGNED_INT, (void*)(447 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 12, GL_UNSIGNED_INT, (void*)(451 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 14, GL_UNSIGNED_INT, (void*)(463 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 9, GL_UNSIGNED_INT, (void*)(477 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 9, GL_UNSIGNED_INT, (void*)(486 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 3, GL_UNSIGNED_INT, (void*)(495 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 9, GL_UNSIGNED_INT, (void*)(498 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 5, GL_UNSIGNED_INT, (void*)(507 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 4, GL_UNSIGNED_INT, (void*)(512 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 5, GL_UNSIGNED_INT, (void*)(516 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 6, GL_UNSIGNED_INT, (void*)(521 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 5, GL_UNSIGNED_INT, (void*)(527 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 3, GL_UNSIGNED_INT, (void*)(532 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 5, GL_UNSIGNED_INT, (void*)(535 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 4, GL_UNSIGNED_INT, (void*)(540 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 3, GL_UNSIGNED_INT, (void*)(544 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 3, GL_UNSIGNED_INT, (void*)(547 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 10, GL_UNSIGNED_INT, (void*)(550 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 6, GL_UNSIGNED_INT, (void*)(560 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 3, GL_UNSIGNED_INT, (void*)(566 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 5, GL_UNSIGNED_INT, (void*)(569 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 4, GL_UNSIGNED_INT, (void*)(574 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 3, GL_UNSIGNED_INT, (void*)(578 * sizeof(float)));
	glDrawElements(GL_LINES, 4, GL_UNSIGNED_INT, (void*)(581 *sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 3, GL_UNSIGNED_INT, (void*)(585 * sizeof(float)));
	glDrawElements(GL_LINE_STRIP, 16, GL_UNSIGNED_INT, (void*)(588 * sizeof(float)));
	glDrawElements(GL_LINE_STRIP, 4, GL_UNSIGNED_INT, (void*)(604 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 3, GL_UNSIGNED_INT, (void*)(608 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 4, GL_UNSIGNED_INT, (void*)(611 * sizeof(float)));
	glDrawElements(GL_LINE_STRIP, 3, GL_UNSIGNED_INT, (void*)(615 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 3, GL_UNSIGNED_INT, (void*)(618 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 3, GL_UNSIGNED_INT, (void*)(621 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 8, GL_UNSIGNED_INT, (void*)(624 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 6, GL_UNSIGNED_INT, (void*)(632 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 8, GL_UNSIGNED_INT, (void*)(638 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 6, GL_UNSIGNED_INT, (void*)(646 * sizeof(float)));
	glDrawElements(GL_LINE_STRIP, 3, GL_UNSIGNED_INT, (void*)(652 * sizeof(float)));
	glDrawElements(GL_LINE_STRIP, 4, GL_UNSIGNED_INT, (void*)(655 * sizeof(float)));
	glDrawElements(GL_LINE_STRIP, 4, GL_UNSIGNED_INT, (void*)(659 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 4, GL_UNSIGNED_INT, (void*)(663 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 6, GL_UNSIGNED_INT, (void*)(667 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 5, GL_UNSIGNED_INT, (void*)(673 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 3, GL_UNSIGNED_INT, (void*)(678 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 6, GL_UNSIGNED_INT, (void*)(681 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 3, GL_UNSIGNED_INT, (void*)(687 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 3, GL_UNSIGNED_INT, (void*)(690 * sizeof(float)));
	glDrawElements(GL_TRIANGLE_FAN, 3, GL_UNSIGNED_INT, (void*)(693 * sizeof(float)));
	glBindVertexArray(0);

}


int main()
{
	// glfw: initialize and configure
	// ------------------------------
	glfwInit();
	/*glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);*/

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif

	// glfw window creation
	// --------------------
	monitors = glfwGetPrimaryMonitor();
	getResolution();

	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "XAYAH AND RAKAN STAR GUARDIANS", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwSetWindowPos(window, 0, 30);
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, resize);

	glewInit();


	//Mis funciones
	//Datos a utilizar
	myData();
	glEnable(GL_DEPTH_TEST);

	//Shader myShader("shaders/shader.vs", "shaders/shader.fs");
	Shader projectionShader("shaders/shader_projection.vs", "shaders/shader_projection.fs");

	// render loop
	// While the windows is not closed
	while (!glfwWindowShouldClose(window))
	{
		// input
		// -----
		my_input(window);

		// render
		// Backgound color
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Mi función de dibujo
		display(projectionShader);

		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		// -------------------------------------------------------------------------------
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// glfw: terminate, clearing all previously allocated GLFW resources.
	// ------------------------------------------------------------------
	glfwTerminate();
	return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void my_input(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)  //GLFW_RELEASE
		glfwSetWindowShouldClose(window, true);



}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void resize(GLFWwindow* window, int width, int height)
{
	// Set the Viewport to the size of the created window
	glViewport(0, 0, width, height);
}
