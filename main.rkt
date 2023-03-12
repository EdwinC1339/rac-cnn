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
