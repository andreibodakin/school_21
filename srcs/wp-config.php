<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'klavada_db' );

/** MySQL database username */
define( 'DB_USER', 'admin' );

/** MySQL database password */
define( 'DB_PASSWORD', 'pass' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         'ulh&65+46wP/jGij)D-9^5w6_>;{=pXH=;,OWF4#<+5((C2u{:K|B^oY bk3.;Qm');
define('SECURE_AUTH_KEY',  '__Y4?7_sa0iD5aw)VW-RC5ZyPM@u<2A~E5cFib H.Fa?-bb}_*leL6F){G4YnfEi');
define('LOGGED_IN_KEY',    'LWvYgstA0 H&n-(w~@iJ*7G2,G6NnBX|/p[:w/_aG+v;K/6Ol5&zP@yEm!Inv@]C');
define('NONCE_KEY',        '}wy[vuCsh{8w,,e7.+Q+RE9 <Jl-_.Rr3OmE.eB/~oJ;j6WktL7fXJTxusV5{as8');
define('AUTH_SALT',        'Y%~E_KZKPl(mN,  tqg]^IELKX|wvxFqI!gSmaX:h8>34^ee*fkNWqyvH{sBUgun');
define('SECURE_AUTH_SALT', 'agt-m;CV^c`==[B*K}$%z|yK;|E>:c`(~}m%BrMU3 ;Z~YrPURJ1hRYQGGp--ZfG');
define('LOGGED_IN_SALT',   'D^^f#Vy-45F-ESd|_(4lT:3?o&>Ff.uXz$Q$c{kT{-kNlHM$dDL3*eK{R-vzq*qH');
define('NONCE_SALT',       'J(2C,6+Hd}>B8R1{)S*f5E8d0wJ(6@+4j74jy2<eU+H$o8Qa 6=C6<8s>d9`+`-1');
/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
