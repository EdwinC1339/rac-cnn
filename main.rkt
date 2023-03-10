#lang racket/base
(require ffi/unsafe
         ffi/unsafe/define)
 
(define-ffi-definer define-cnn (ffi-lib ".\\libCNN\\x64\\Debug\\libCNN"))

(define-cnn fibonacci_init (_fun _int _int -> _void))
(define-cnn fibonacci_next (_fun -> _bool))
(define-cnn fibonacci_current (_fun -> _int))

(define (init) (fibonacci_init 1 1))
(define (next) (fibonacci_next))
(define (current) (fibonacci_current))

(void (init))

(define (fib n) (cond
    ((= n 0) (list (current)))
    (else (cons (car (cons (current) (next))) (fib (- n 1))))
))