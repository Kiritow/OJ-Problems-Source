#include <windows.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char clipbuffer[1024];
char uname[1024];
char cmessage[1024];
char fname[1024];
int tid;
void GetClipData()
{
    OpenClipboard(NULL);
    HANDLE hClipboardData=GetClipboardData(CF_TEXT);
    char* pchData=(char*)GlobalLock(hClipboardData);
    strcpy(clipbuffer,pchData);
    GlobalUnlock(hClipboardData);
    CloseClipboard();
}

void SplitData()
{
    char* p=strstr(clipbuffer,"://")+3;
    p=strstr(p,"/");
    char* q=strstr(p+1,"/");
    strncpy(uname,p+1,q-p-1);
    sprintf(cmessage,"From %s",clipbuffer);
}

void GetFileNum()
{
    printf("Please input Problem ID:\n");
    scanf("%d%*c",&tid);
    sprintf(fname,"%d_%s.cpp",tid,uname);
}

void SetClip(const char* inc)
{
    OpenClipboard(NULL);
    EmptyClipboard();
    HGLOBAL hClipboardData;
    hClipboardData=GlobalAlloc(GMEM_DDESHARE,strlen(inc)+1);
    char* pchData;
    pchData=(char*)GlobalLock(hClipboardData);
    strcpy(pchData,inc);
    GlobalUnlock(hClipboardData);
    SetClipboardData(CF_TEXT,hClipboardData);
    CloseClipboard();
}

void PrintFileName()
{
    SetClip(fname);
    printf("File Name Set.\n");
}
void PrintCommentMessage()
{
    SetClip(cmessage);
    printf("Comment Message Set.\n");
}
void ShowClip()
{
    printf("Data In Clipboard...\n");
    printf("%s\n",clipbuffer);
}
void GPause()
{
    getchar();
}
int main()
{
    printf("Link Start!\n");
    GetClipData();
    ShowClip();
    SplitData();
    GetFileNum();
    PrintFileName();
    GPause();
    PrintCommentMessage();
    return 0;
}

