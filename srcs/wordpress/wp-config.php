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
 * @link https://codex.wordpress.org/Editing_wp-config.php
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define('DB_NAME', 'wp_db');

/** MySQL database username */
define('DB_USER', 'klavada');

/** MySQL database password */
define('DB_PASSWORD', 'school21');

/** MySQL hostname */
define('DB_HOST', 'mysql-ser:3306');

define('WP_HOME', 'http://192.168.99.100:5050/' );

define('WP_SITEURL', 'http://192.168.99.100:5050/' );
/** Database Charset to use in creating database tables. */
define('DB_CHARSET', 'utf8');

/** The Database Collate type. Don't change this if in doubt. */
define('DB_COLLATE', '');

define('FS_METHOD', 'direct');

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         'aruw:,Igt{6eZft1D-$hR+9Q^{BSMAsMgdcD1(t`*X<.(f4[Gyi,j+TrmpU#-]1Z');
define('SECURE_AUTH_KEY',  'x+sf-WiGy1u-X-NIlOL@vDtGuy,aP$*To??CI#R@{jcaYS^1N_W@M3i#8t*JDix%');
define('LOGGED_IN_KEY',    'F+>K(VfJ5]me:nVlr<f0 r(8hKl?HcSIehkscJB|X!sk%#}{QDt4S<Yvon!]`2xE');
define('NONCE_KEY',        'Xb#,cj32)L)6vW8hL$/yQ{-7)^-Jrf^v>ew-!hFe|9NU1h,~b02!{0K-Bfku$=K1');
define('AUTH_SALT',        '#+b]#PFGfDJM*3u@AR*Ft%]u0~1&kvXw-8pfjRjip+=#.7FR 5F;vGKmt5l1U-4E');
define('SECURE_AUTH_SALT', '+:.DMZdxPO,Y)=+n5qL{.i[p64H`C5=0>?+~0,Ie*;`4I8]K2||[s4jKY+%t].:3');
define('LOGGED_IN_SALT',   'SQi`3MGp|{,kb 1<J.0h?Y33#=/1u+6rdKjIf3QIImO|mSj$g8~RNX5mu$d[6;/~');
define('NONCE_SALT',       's:H(j-OIjSGXgX~aQ7*t;<+*Mm|K[pjPsf~:2wy:e`+D9,=Hm0q3eK9xtXNPH5^`');

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix  = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the Codex.
 *
 * @link https://codex.wordpress.org/Debugging_in_WordPress
 */
define('WP_DEBUG', true);

/* That's all, stop editing! Happy blogging. */

/** Absolute path to the WordPress directory. 
 * It prevent public user to directly access your .php files through URL. 
 * Because if your file contains some I/O operations 
 * it can eventually be triggered (by an attacker) and this might cause unexpected behavior.
*/
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
