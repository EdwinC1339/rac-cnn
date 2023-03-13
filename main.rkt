#lang racket/base
(require ffi/unsafe
         ffi/unsafe/define)
 
(ffi-lib ".\\libCNN\\fftw-3.3.5-dll64\\libfftw3-3")
(define-ffi-definer define-cnn (ffi-lib ".\\libCNN\\x64\\Debug\\libCNN"))

(define (ensure-inexact n) (if (inexact? n) n (exact->inexact n)))

(define (number->complex-double n) (list (ensure-inexact (real-part n)) (ensure-inexact (imag-part n))))
(define (complex-double->number l) (+ (car l) (* (cadr l) 0+i)))

(define complex-double (make-ctype 
    (_list-struct _double _double)
    number->complex-double
    complex-double->number   
))

(define-cnn fft (_fun 
    (n : _int) 
    (_vector i complex-double) 
    (o : (_vector o complex-double n)) 
    -> _bool 
    -> o))

