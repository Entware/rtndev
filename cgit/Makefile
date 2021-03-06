#
# Copyright (C) 2009-2018 OpenWrt.org
# Copyright (C) 2018-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=cgit
PKG_VERSION:=1.2.3
PKG_RELEASE:=1
PKG_REV:=55fa25adb097d2681607d8b0f51a0c393cc9af1a

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://git.zx2c4.com/cgit
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=28231068e5be3dd397fc5c70ae43471e4954a395abc8f9025850f413c2d61d29

PKG_LICENSE:=GPL-2.0
PKG_LICENSE_FILES:=COPYING

PKG_INSTALL:=1
PKG_BUILD_PARALLEL:=1
PKG_FIXUP:=autoreconf

include $(INCLUDE_DIR)/package.mk

define Package/cgit
	TITLE:=Web interface (cgi) for Git repositories, written in C
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=Version Control Systems
	DEPENDS:=+libopenssl +libpthread +librt +zlib +liblua
	URL:=https://git.zx2c4.com/cgit/
	MAINTAINER:=Troels Gram [https://github.com/tgram75]
endef

define Package/cgit/description
 Cgit is a web interface (cgi) for Git repositories, written in C
 This is an attempt to create a fast web interface for the Git
 SCM, using a built-in cache to decrease server I/O pressure.
endef

MAKE_FLAGS := \
	CC="$(TARGET_CC)" \
	CFLAGS="$(TARGET_CFLAGS)" \
	CPPFLAGS="$(TARGET_CPPFLAGS)" \
	LDFLAGS="$(TARGET_LDFLAGS)" \
	NO_EXPAT="YesPlease" \
	NO_MKSTEMPS="YesPlease" \
	NO_GETTEXT="YesPlease" \
	NO_UNIX_SOCKETS="YesPlease" \
	NO_ICONV="YesPlease" \
	NO_NSEC="YesPlease" \
	NO_PERL="YesPlease" \
	NO_PYTHON="YesPlease" \
	NO_TCLTK="YesPlease" \
	NO_INSTALL_HARDLINKS="yes" \
	LUA_PKGCONFIG="lua"

CONFIGURE_ARGS += \
	--without-iconv

define Package/cgit/install
	$(INSTALL_DIR) $(1)/opt/var/www/htdocs/cgit
	$(CP) $(PKG_INSTALL_DIR)/var/www/htdocs/cgit/* $(1)/opt/var/www/htdocs/cgit
	$(INSTALL_DIR) $(1)/opt/usr/local/lib/cgit/filters
	$(CP) $(PKG_INSTALL_DIR)/usr/local/lib/cgit/filters/* $(1)/opt/usr/local/lib/cgit/filters
	# Entware specific: fix exec path in scripts
	$(SED) 's,^#!.*bash,#!/opt/bin/bash,' \
		$(1)/opt/usr/local/lib/cgit/filters/html-converters/rst2html
	$(SED) 's,^#!.*python,#!/opt/bin/python,' \
		$(1)/opt/usr/local/lib/cgit/filters/email-gravatar.py \
		$(1)/opt/usr/local/lib/cgit/filters/html-converters/md2html \
		$(1)/opt/usr/local/lib/cgit/filters/syntax-highlighting.py
endef

$(eval $(call BuildPackage,cgit))
