#include "OpenGL.h"
#include "GLWindow.h"


#define _INITEXT_(TYPE,NAME)\
{\
	NAME = (TYPE)wglGetProcAddress(#NAME);\
	if(!NAME)\
		return false;\
}


PFNWGLSWAPINTERVALEXTPROC				wglSwapIntervalEXT;
PFNWGLCHOOSEPIXELFORMATARBPROC			wglChoosePixelFormatARB;
PFNWGLCREATECONTEXTATTRIBSARBPROC		wglCreateContextAttribsARB;
PFNGLACTIVETEXTUREPROC					glActiveTexture;
PFNGLMULTIDRAWARRAYSPROC				glMultiDrawArrays;
PFNGLMULTIDRAWELEMENTSPROC				glMultiDrawElements;
PFNGLBINDBUFFERPROC						glBindBuffer;
PFNGLDELETEBUFFERSPROC					glDeleteBuffers;
PFNGLGENBUFFERSPROC						glGenBuffers;
PFNGLBUFFERDATAPROC						glBufferData;
PFNGLBUFFERSUBDATAPROC					glBufferSubData;
PFNGLBLENDEQUATIONSEPARATEPROC			glBlendEquationSeparate;
PFNGLATTACHSHADERPROC					glAttachShader;
PFNGLCOMPILESHADERPROC					glCompileShader;
PFNGLCREATEPROGRAMPROC					glCreateProgram;
PFNGLCREATESHADERPROC					glCreateShader;
PFNGLDELETEPROGRAMPROC					glDeleteProgram;
PFNGLDELETESHADERPROC					glDeleteShader;
PFNGLGETPROGRAMIVPROC					glGetProgramiv;
PFNGLGETSHADERIVPROC					glGetShaderiv;
PFNGLGETUNIFORMLOCATIONPROC				glGetUniformLocation;
PFNGLLINKPROGRAMPROC					glLinkProgram;
PFNGLSHADERSOURCEPROC					glShaderSource;
PFNGLUSEPROGRAMPROC						glUseProgram;
PFNGLBLENDCOLORPROC						glBlendColor;
PFNGLUNIFORM1FPROC						glUniform1f;
PFNGLUNIFORM2FPROC						glUniform2f;
PFNGLUNIFORM3FPROC						glUniform3f;
PFNGLUNIFORM4FPROC						glUniform4f;
PFNGLUNIFORM1FVPROC						glUniform1fv;
PFNGLUNIFORM2FVPROC						glUniform2fv;
PFNGLUNIFORM3FVPROC						glUniform3fv;
PFNGLUNIFORM4FVPROC						glUniform4fv;
PFNGLUNIFORM1DPROC						glUniform1d;
PFNGLUNIFORM2DPROC						glUniform2d;
PFNGLUNIFORM3DPROC						glUniform3d;
PFNGLUNIFORM4DPROC						glUniform4d;
PFNGLUNIFORM1DVPROC						glUniform1dv;
PFNGLUNIFORM2DVPROC						glUniform2dv;
PFNGLUNIFORM3DVPROC						glUniform3dv;
PFNGLUNIFORM4DVPROC						glUniform4dv;
PFNGLUNIFORM1IPROC						glUniform1i;
PFNGLUNIFORM2IPROC						glUniform2i;
PFNGLUNIFORM3IPROC						glUniform3i;
PFNGLUNIFORM4IPROC						glUniform4i;
PFNGLUNIFORM1IVPROC						glUniform1iv;
PFNGLUNIFORM2IVPROC						glUniform2iv;
PFNGLUNIFORM3IVPROC						glUniform3iv;
PFNGLUNIFORM4IVPROC						glUniform4iv;
PFNGLUNIFORMMATRIX3FVPROC				glUniformMatrix3fv;
PFNGLUNIFORMMATRIX3DVPROC				glUniformMatrix3dv;
PFNGLUNIFORMMATRIX4FVPROC				glUniformMatrix4fv;
PFNGLUNIFORMMATRIX4DVPROC				glUniformMatrix4dv;
PFNGLGENFRAMEBUFFERSPROC				glGenFramebuffers;
PFNGLBINDFRAMEBUFFERPROC				glBindFramebuffer;
PFNGLBINDRENDERBUFFERPROC				glBindRenderbuffer;
PFNGLGENRENDERBUFFERSPROC				glGenRenderbuffers;
PFNGLRENDERBUFFERSTORAGEPROC			glRenderbufferStorage;
PFNGLFRAMEBUFFERTEXTUREPROC				glFramebufferTexture;
PFNGLFRAMEBUFFERTEXTURE2DPROC			glFramebufferTexture2D;
PFNGLDRAWBUFFERSPROC					glDrawBuffers;
PFNGLENABLEVERTEXATTRIBARRAYPROC		glEnableVertexAttribArray;
PFNGLDISABLEVERTEXATTRIBARRAYPROC		glDisableVertexAttribArray;
PFNGLVERTEXATTRIBPOINTERPROC			glVertexAttribPointer;
PFNGLVERTEXATTRIBIPOINTERPROC			glVertexAttribIPointer;
PFNGLBINDATTRIBLOCATIONPROC				glBindAttribLocation;
PFNGLCHECKFRAMEBUFFERSTATUSPROC			glCheckFramebufferStatus;
PFNGLGETSHADERINFOLOGPROC				glGetShaderInfoLog;
PFNGLGETPROGRAMINFOLOGPROC				glGetProgramInfoLog;
PFNGLBINDVERTEXARRAYPROC				glBindVertexArray;
PFNGLDELETEVERTEXARRAYSPROC				glDeleteVertexArrays;
PFNGLGENVERTEXARRAYSPROC				glGenVertexArrays;
PFNGLMAPBUFFERPROC						glMapBuffer;
PFNGLUNMAPBUFFERPROC					glUnmapBuffer;
PFNGLBLENDFUNCSEPARATEPROC				glBlendFuncSeparate;
PFNGLGETATTRIBLOCATIONPROC				glGetAttribLocation;
PFNGLGENERATEMIPMAPPROC					glGenerateMipmap;
PFNGLENABLEIPROC						glEnablei;
PFNGLDISABLEIPROC						glDisablei;
PFNGLBEGINTRANSFORMFEEDBACKPROC			glBeginTransformFeedback;
PFNGLENDTRANSFORMFEEDBACKPROC			glEndTransformFeedback;
PFNGLTRANSFORMFEEDBACKVARYINGSPROC		glTransformFeedbackVaryings;
PFNGLFRAMEBUFFERRENDERBUFFERPROC		glFramebufferRenderbuffer;
PFNGLBINDFRAGDATALOCATIONPROC			glBindFragDataLocation;
PFNGLBINDBUFFERBASEPROC					glBindBufferBase;
PFNGLBEGINQUERYPROC						glBeginQuery;
PFNGLENDQUERYPROC						glEndQuery;
PFNGLGETTRANSFORMFEEDBACKVARYINGPROC	glGetTransformFeedbackVarying;
PFNGLGETQUERYOBJECTUIVPROC				glGetQueryObjectuiv;
PFNGLGENQUERIESPROC						glGenQueries;
PFNGLBINDBUFFERRANGEPROC				glBindBufferRange;
PFNGLDELETEFRAMEBUFFERSPROC				glDeleteFramebuffers;
PFNGLTEXBUFFERPROC						glTexBuffer;
PFNGLBLITFRAMEBUFFERPROC				glBlitFramebuffer;
PFNGLTEXIMAGE3DPROC						glTexImage3D;
PFNGLGETQUERYIVPROC						glGetQueryiv;
PFNGLGETINTEGER64VPROC					glGetInteger64v;


bool InitWGLExtensions()
{
	_INITEXT_(PFNWGLCHOOSEPIXELFORMATARBPROC, wglChoosePixelFormatARB);
	_INITEXT_(PFNWGLCREATECONTEXTATTRIBSARBPROC, wglCreateContextAttribsARB);

	return true;
}


bool InitOpenGLExtensions()
{
	_INITEXT_(PFNWGLSWAPINTERVALEXTPROC, wglSwapIntervalEXT);
	_INITEXT_(PFNGLACTIVETEXTUREPROC, glActiveTexture);
	_INITEXT_(PFNGLMULTIDRAWARRAYSPROC, glMultiDrawArrays);
	_INITEXT_(PFNGLMULTIDRAWELEMENTSPROC, glMultiDrawElements);
	_INITEXT_(PFNGLBINDBUFFERPROC, glBindBuffer);
	_INITEXT_(PFNGLDELETEBUFFERSPROC, glDeleteBuffers);
	_INITEXT_(PFNGLGENBUFFERSPROC, glGenBuffers);
	_INITEXT_(PFNGLBUFFERDATAPROC, glBufferData);
	_INITEXT_(PFNGLBUFFERSUBDATAPROC, glBufferSubData);
	_INITEXT_(PFNGLBLENDEQUATIONSEPARATEPROC, glBlendEquationSeparate);
	_INITEXT_(PFNGLATTACHSHADERPROC, glAttachShader);
	_INITEXT_(PFNGLCOMPILESHADERPROC, glCompileShader);
	_INITEXT_(PFNGLCREATEPROGRAMPROC, glCreateProgram);
	_INITEXT_(PFNGLCREATESHADERPROC, glCreateShader);
	_INITEXT_(PFNGLDELETEPROGRAMPROC, glDeleteProgram);
	_INITEXT_(PFNGLDELETESHADERPROC, glDeleteShader);
	_INITEXT_(PFNGLGETPROGRAMIVPROC, glGetProgramiv);
	_INITEXT_(PFNGLGETSHADERIVPROC, glGetShaderiv);
	_INITEXT_(PFNGLGETUNIFORMLOCATIONPROC, glGetUniformLocation);
	_INITEXT_(PFNGLLINKPROGRAMPROC, glLinkProgram);
	_INITEXT_(PFNGLSHADERSOURCEPROC, glShaderSource);
	_INITEXT_(PFNGLUSEPROGRAMPROC, glUseProgram);
	_INITEXT_(PFNGLBLENDCOLORPROC, glBlendColor);
	_INITEXT_(PFNGLUNIFORM1FPROC, glUniform1f);
	_INITEXT_(PFNGLUNIFORM2FPROC, glUniform2f);
	_INITEXT_(PFNGLUNIFORM3FPROC, glUniform3f);
	_INITEXT_(PFNGLUNIFORM4FPROC, glUniform4f);
	_INITEXT_(PFNGLUNIFORM1FVPROC, glUniform1fv);
	_INITEXT_(PFNGLUNIFORM2FVPROC, glUniform2fv);
	_INITEXT_(PFNGLUNIFORM3FVPROC, glUniform3fv);
	_INITEXT_(PFNGLUNIFORM4FVPROC, glUniform4fv);
	_INITEXT_(PFNGLUNIFORM1DPROC, glUniform1d);
	_INITEXT_(PFNGLUNIFORM2DPROC, glUniform2d);
	_INITEXT_(PFNGLUNIFORM3DPROC, glUniform3d);
	_INITEXT_(PFNGLUNIFORM4DPROC, glUniform4d);
	_INITEXT_(PFNGLUNIFORM1DVPROC, glUniform1dv);
	_INITEXT_(PFNGLUNIFORM2DVPROC, glUniform2dv);
	_INITEXT_(PFNGLUNIFORM3DVPROC, glUniform3dv);
	_INITEXT_(PFNGLUNIFORM4DVPROC, glUniform4dv);
	_INITEXT_(PFNGLUNIFORM1IPROC, glUniform1i);
	_INITEXT_(PFNGLUNIFORM2IPROC, glUniform2i);
	_INITEXT_(PFNGLUNIFORM3IPROC, glUniform3i);
	_INITEXT_(PFNGLUNIFORM4IPROC, glUniform4i);
	_INITEXT_(PFNGLUNIFORM1IVPROC, glUniform1iv);
	_INITEXT_(PFNGLUNIFORM2IVPROC, glUniform2iv);
	_INITEXT_(PFNGLUNIFORM3IVPROC, glUniform3iv);
	_INITEXT_(PFNGLUNIFORM4IVPROC, glUniform4iv);
	_INITEXT_(PFNGLUNIFORMMATRIX3FVPROC, glUniformMatrix3fv);
	_INITEXT_(PFNGLUNIFORMMATRIX3DVPROC, glUniformMatrix3dv);
	_INITEXT_(PFNGLUNIFORMMATRIX4FVPROC, glUniformMatrix4fv);
	_INITEXT_(PFNGLUNIFORMMATRIX4DVPROC, glUniformMatrix4dv);
	_INITEXT_(PFNGLGENFRAMEBUFFERSPROC, glGenFramebuffers);
	_INITEXT_(PFNGLBINDFRAMEBUFFERPROC, glBindFramebuffer);
	_INITEXT_(PFNGLBINDRENDERBUFFERPROC, glBindRenderbuffer);
	_INITEXT_(PFNGLGENRENDERBUFFERSPROC, glGenRenderbuffers);
	_INITEXT_(PFNGLRENDERBUFFERSTORAGEPROC, glRenderbufferStorage);
	_INITEXT_(PFNGLFRAMEBUFFERTEXTUREPROC, glFramebufferTexture);
	_INITEXT_(PFNGLFRAMEBUFFERTEXTURE2DPROC, glFramebufferTexture2D);
	_INITEXT_(PFNGLDRAWBUFFERSPROC, glDrawBuffers);
	_INITEXT_(PFNGLENABLEVERTEXATTRIBARRAYPROC, glEnableVertexAttribArray);
	_INITEXT_(PFNGLDISABLEVERTEXATTRIBARRAYPROC, glDisableVertexAttribArray);
	_INITEXT_(PFNGLVERTEXATTRIBPOINTERPROC, glVertexAttribPointer);
	_INITEXT_(PFNGLVERTEXATTRIBIPOINTERPROC, glVertexAttribIPointer);
	_INITEXT_(PFNGLBINDATTRIBLOCATIONPROC, glBindAttribLocation);
	_INITEXT_(PFNGLCHECKFRAMEBUFFERSTATUSPROC, glCheckFramebufferStatus);
	_INITEXT_(PFNGLGETSHADERINFOLOGPROC, glGetShaderInfoLog);
	_INITEXT_(PFNGLGETPROGRAMINFOLOGPROC, glGetProgramInfoLog);
	_INITEXT_(PFNGLBINDVERTEXARRAYPROC, glBindVertexArray);
	_INITEXT_(PFNGLDELETEVERTEXARRAYSPROC, glDeleteVertexArrays);
	_INITEXT_(PFNGLGENVERTEXARRAYSPROC, glGenVertexArrays);
	_INITEXT_(PFNGLMAPBUFFERPROC, glMapBuffer);
	_INITEXT_(PFNGLUNMAPBUFFERPROC, glUnmapBuffer);
	_INITEXT_(PFNGLBLENDFUNCSEPARATEPROC, glBlendFuncSeparate);
	_INITEXT_(PFNGLGETATTRIBLOCATIONPROC, glGetAttribLocation);
	_INITEXT_(PFNGLGENERATEMIPMAPPROC, glGenerateMipmap);
	_INITEXT_(PFNGLENABLEIPROC, glEnablei);
	_INITEXT_(PFNGLDISABLEIPROC, glDisablei);
	_INITEXT_(PFNGLBEGINTRANSFORMFEEDBACKPROC, glBeginTransformFeedback);
	_INITEXT_(PFNGLENDTRANSFORMFEEDBACKPROC, glEndTransformFeedback);
	_INITEXT_(PFNGLTRANSFORMFEEDBACKVARYINGSPROC, glTransformFeedbackVaryings);
	_INITEXT_(PFNGLFRAMEBUFFERRENDERBUFFERPROC, glFramebufferRenderbuffer);
	_INITEXT_(PFNGLBINDFRAGDATALOCATIONPROC, glBindFragDataLocation);
	_INITEXT_(PFNGLBINDBUFFERBASEPROC, glBindBufferBase);
	_INITEXT_(PFNGLBEGINQUERYPROC, glBeginQuery);
	_INITEXT_(PFNGLENDQUERYPROC, glEndQuery);
	_INITEXT_(PFNGLGETTRANSFORMFEEDBACKVARYINGPROC, glGetTransformFeedbackVarying);
	_INITEXT_(PFNGLGETQUERYOBJECTUIVPROC, glGetQueryObjectuiv);
	_INITEXT_(PFNGLGENQUERIESPROC, glGenQueries);
	_INITEXT_(PFNGLBINDBUFFERRANGEPROC, glBindBufferRange);
	_INITEXT_(PFNGLDELETEFRAMEBUFFERSPROC, glDeleteFramebuffers);
	_INITEXT_(PFNGLTEXBUFFERPROC, glTexBuffer);
	_INITEXT_(PFNGLBLITFRAMEBUFFERPROC, glBlitFramebuffer);
	_INITEXT_(PFNGLTEXIMAGE3DPROC, glTexImage3D);
	_INITEXT_(PFNGLGETQUERYIVPROC, glGetQueryiv);
	_INITEXT_(PFNGLGETINTEGER64VPROC, glGetInteger64v);

	return true;
}