#pragma once

#pragma comment(lib, "opengl32.lib")

#include <Windows.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <gl\wglext.h>

#define GLM_FORCE_RADIANS
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

using namespace glm;


bool InitWGLExtensions();
bool InitOpenGLExtensions();


extern PFNWGLSWAPINTERVALEXTPROC			wglSwapIntervalEXT;
extern PFNWGLCHOOSEPIXELFORMATARBPROC		wglChoosePixelFormatARB;
extern PFNWGLCREATECONTEXTATTRIBSARBPROC	wglCreateContextAttribsARB;
extern PFNGLACTIVETEXTUREPROC				glActiveTexture;
extern PFNGLMULTIDRAWARRAYSPROC				glMultiDrawArrays;
extern PFNGLMULTIDRAWELEMENTSPROC			glMultiDrawElements;
extern PFNGLBINDBUFFERPROC					glBindBuffer;
extern PFNGLDELETEBUFFERSPROC				glDeleteBuffers;
extern PFNGLGENBUFFERSPROC					glGenBuffers;
extern PFNGLBUFFERDATAPROC					glBufferData;
extern PFNGLBUFFERSUBDATAPROC				glBufferSubData;
extern PFNGLBLENDEQUATIONSEPARATEPROC		glBlendEquationSeparate;
extern PFNGLATTACHSHADERPROC				glAttachShader;
extern PFNGLCOMPILESHADERPROC				glCompileShader;
extern PFNGLCREATEPROGRAMPROC				glCreateProgram;
extern PFNGLCREATESHADERPROC				glCreateShader;
extern PFNGLDELETEPROGRAMPROC				glDeleteProgram;
extern PFNGLDELETESHADERPROC				glDeleteShader;
extern PFNGLGETPROGRAMIVPROC				glGetProgramiv;
extern PFNGLGETSHADERIVPROC					glGetShaderiv;
extern PFNGLGETUNIFORMLOCATIONPROC			glGetUniformLocation;
extern PFNGLLINKPROGRAMPROC					glLinkProgram;
extern PFNGLSHADERSOURCEPROC				glShaderSource;
extern PFNGLUSEPROGRAMPROC					glUseProgram;
extern PFNGLBLENDCOLORPROC					glBlendColor;
extern PFNGLUNIFORM1FPROC					glUniform1f;
extern PFNGLUNIFORM2FPROC					glUniform2f;
extern PFNGLUNIFORM3FPROC					glUniform3f;
extern PFNGLUNIFORM4FPROC					glUniform4f;
extern PFNGLUNIFORM1FVPROC					glUniform1fv;
extern PFNGLUNIFORM2FVPROC					glUniform2fv;
extern PFNGLUNIFORM3FVPROC					glUniform3fv;
extern PFNGLUNIFORM4FVPROC					glUniform4fv;
extern PFNGLUNIFORM1DPROC					glUniform1d;
extern PFNGLUNIFORM2DPROC					glUniform2d;
extern PFNGLUNIFORM3DPROC					glUniform3d;
extern PFNGLUNIFORM4DPROC					glUniform4d;
extern PFNGLUNIFORM1DVPROC					glUniform1dv;
extern PFNGLUNIFORM2DVPROC					glUniform2dv;
extern PFNGLUNIFORM3DVPROC					glUniform3dv;
extern PFNGLUNIFORM4DVPROC					glUniform4dv;
extern PFNGLUNIFORM1IPROC					glUniform1i;
extern PFNGLUNIFORM2IPROC					glUniform2i;
extern PFNGLUNIFORM3IPROC					glUniform3i;
extern PFNGLUNIFORM4IPROC					glUniform4i;
extern PFNGLUNIFORM1IVPROC					glUniform1iv;
extern PFNGLUNIFORM2IVPROC					glUniform2iv;
extern PFNGLUNIFORM3IVPROC					glUniform3iv;
extern PFNGLUNIFORM4IVPROC					glUniform4iv;
extern PFNGLUNIFORMMATRIX3FVPROC			glUniformMatrix3fv;
extern PFNGLUNIFORMMATRIX3DVPROC			glUniformMatrix3dv;
extern PFNGLUNIFORMMATRIX4FVPROC			glUniformMatrix4fv;
extern PFNGLUNIFORMMATRIX4DVPROC			glUniformMatrix4dv;
extern PFNGLGENFRAMEBUFFERSPROC				glGenFramebuffers;
extern PFNGLBINDFRAMEBUFFERPROC				glBindFramebuffer;
extern PFNGLBINDRENDERBUFFERPROC			glBindRenderbuffer;
extern PFNGLGENRENDERBUFFERSPROC			glGenRenderbuffers;
extern PFNGLRENDERBUFFERSTORAGEPROC			glRenderbufferStorage;
extern PFNGLFRAMEBUFFERTEXTUREPROC			glFramebufferTexture;
extern PFNGLFRAMEBUFFERTEXTURE2DPROC		glFramebufferTexture2D;
extern PFNGLDRAWBUFFERSPROC					glDrawBuffers;
extern PFNGLENABLEVERTEXATTRIBARRAYPROC		glEnableVertexAttribArray;
extern PFNGLDISABLEVERTEXATTRIBARRAYPROC	glDisableVertexAttribArray;
extern PFNGLVERTEXATTRIBPOINTERPROC			glVertexAttribPointer;
extern PFNGLVERTEXATTRIBIPOINTERPROC		glVertexAttribIPointer;
extern PFNGLBINDATTRIBLOCATIONPROC			glBindAttribLocation;
extern PFNGLCHECKFRAMEBUFFERSTATUSPROC		glCheckFramebufferStatus;
extern PFNGLGETSHADERINFOLOGPROC			glGetShaderInfoLog;
extern PFNGLGETPROGRAMINFOLOGPROC			glGetProgramInfoLog;
extern PFNGLBINDVERTEXARRAYPROC				glBindVertexArray;
extern PFNGLDELETEVERTEXARRAYSPROC			glDeleteVertexArrays;
extern PFNGLGENVERTEXARRAYSPROC				glGenVertexArrays;
extern PFNGLMAPBUFFERPROC					glMapBuffer;
extern PFNGLUNMAPBUFFERPROC					glUnmapBuffer;
extern PFNGLBLENDFUNCSEPARATEPROC			glBlendFuncSeparate;
extern PFNGLGETATTRIBLOCATIONPROC			glGetAttribLocation;
extern PFNGLGENERATEMIPMAPPROC				glGenerateMipmap;
extern PFNGLENABLEIPROC						glEnablei;
extern PFNGLDISABLEIPROC					glDisablei;
extern PFNGLBEGINTRANSFORMFEEDBACKPROC		glBeginTransformFeedback;
extern PFNGLENDTRANSFORMFEEDBACKPROC		glEndTransformFeedback;
extern PFNGLTRANSFORMFEEDBACKVARYINGSPROC	glTransformFeedbackVaryings;
extern PFNGLFRAMEBUFFERRENDERBUFFERPROC		glFramebufferRenderbuffer;
extern PFNGLBINDFRAGDATALOCATIONPROC		glBindFragDataLocation;
extern PFNGLBINDBUFFERBASEPROC				glBindBufferBase;
extern PFNGLBEGINQUERYPROC					glBeginQuery;
extern PFNGLENDQUERYPROC					glEndQuery;
extern PFNGLGETTRANSFORMFEEDBACKVARYINGPROC	glGetTransformFeedbackVarying;
extern PFNGLGETQUERYOBJECTUIVPROC			glGetQueryObjectuiv;
extern PFNGLGENQUERIESPROC					glGenQueries;
extern PFNGLBINDBUFFERRANGEPROC				glBindBufferRange;
extern PFNGLDELETEFRAMEBUFFERSPROC			glDeleteFramebuffers;
extern PFNGLTEXBUFFERPROC					glTexBuffer;
extern PFNGLBLITFRAMEBUFFERPROC				glBlitFramebuffer;
extern PFNGLTEXIMAGE3DPROC					glTexImage3D;
extern PFNGLGETQUERYIVPROC					glGetQueryiv;
extern PFNGLGETINTEGER64VPROC				glGetInteger64v;
