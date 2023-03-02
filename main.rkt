#lang racket

(define reals (inclusive-range -2 2 (/ 1 2)))
(define imags (map (lambda (x) (* x 0+i)) reals))

(define plane (map (lambda (p) (apply + p)) (cartesian-product reals imags)))
(display plane)