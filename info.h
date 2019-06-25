/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   info.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/29 23:27:35 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/06/24 13:19:26 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef INFO_H
# define INFO_H

# define WD 1920
# define HH 1080
# define POST (WD * 0.8)
# define WDI (POST + 5)
# define TIN (WD * 0.2)
# define RED 16711680
# define WHITE 16777215
# define TETA (M_PI / 6)

# define ESC    "- ESC ==> Quit program"
# define TRANS  "- LEFT/RIGHT/UP/DOWN ==> Translate"
# define ZP		"- WHEEL UP   ==> Zoom +"
# define ZM 	"- WHEEL DOWN ==> Zoom -"
# define ELE	"- + / - ==> Elevate"
# define CENTER	"- KEY C ==> Center"
# define RESET	"- KEY R ==> Reset Elevation"
# define CRESET	"- KEY A ==> Center + Reset Elevation"
# define SWAPP	"- KEY P ==> Swap Projection"
# define SWAPC	"- KEY S ==> Swap Color Mode"
# define CTB	"- KEY B ==> Color to Black"
# define CTW	"- KEY W ==> Color to White"
# define PMI	"- Proj Mode  ==> Isometric"
# define PMP	"- Proj Mode  ==> Parallel"
# define CMP	"- Color Mode ==> Plain"
# define CMI	"- Color Mode ==> Initial"
# define CMG	"- Color Mode ==> Graduate"
# define JULIA  "Julia"
# define MANDEL "Mandelbrot"
# define KOCH   "Koch"
# define SHIP "Ship"

#endif
