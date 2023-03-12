#lang racket/base
(require ffi/unsafe
         ffi/unsafe/define)
 
(define-ffi-definer define-cnn (ffi-lib ".\\libCNN\\x64\\Debug\\libCNN"))

(define-cnn fibonacci_sequence (_fun 
    [n : _int] 
    [seq : (_vector o _llong n)] 
    -> [res : _bool]
    -> (values seq res)))

(fibonacci_sequence 10) 

(define-cnn add_arrs (_fun
    [n : _int]
    [a : (_list i _double)]
    (_list i _double)
    [sum : (_list o _double n)]
    -> [res : _bool]
    -> (values sum res a)
))

(add_arrs 3 '(1.0 2.0 3.0) '(3.0 1.0 1.0))