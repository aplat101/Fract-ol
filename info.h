/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   info.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/29 23:27:35 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/12 23:43:18 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef INFO_H
# define INFO_H

# define WD 1250
# define HH 1000
# define POST (WD * 0.8)
# define POSTP (POST + 10)
# define INFO (WD * 0.2)
# define THREAD 8

# define ESC    "- ESC ==> Quit program"
# define TRANS  "- LEFT/RIGHT/UP/DOWN ==> Translate"
# define ZP		"- WHEEL UP   ==> Zoom +"
# define ZM 	"- WHEEL DOWN ==> Zoom -"
# define ITER	"- + / - ==> Iterations"
# define CENTER	"- KEY C ==> Center"
# define RESET	"- R ==> Reset Values"
# define CRESET	"- KEY A ==> Center + Reset Elevation"
# define SWAPC	"- C ==> Swap Color"
# define SWAP	"- S ==> Swap Fractal"
# define CTB	"- KEY B ==> Color to Black"
# define CTW	"- KEY W ==> Color to White"
# define VAR	"- V ==> Variant Julia"
# define DIS    "  |__ disabled"
# define ENA    "  |__ enabled"
# define PMP	"- Proj Mode  ==> Parallel"
# define CMP	"- Color Mode ==> Plain"
# define CMI	"- Color Mode ==> Initial"
# define CMG	"- Color Mode ==> Graduate"
# define JULIA  "Julia"
# define MANDEL "Mandelbrot"
# define SHIP 	"Ship"

#endif
