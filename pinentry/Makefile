#
# Copyright (C) 2006-2015 OpenWrt.org
# Copyright (C) 2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=pinentry
PKG_VERSION:=1.1.1
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=https://gnupg.org/ftp/gcrypt/pinentry
PKG_HASH:=c6202b29cf60454d2560debea0371818f26c3f07

PKG_LICENSE:=GPL-2.0+
PKG_LICENSE_FILES:=COPYING

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/pinentry
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Encryption
	DEPENDS:=+libassuan +libncursesw +libcap
	TITLE:=GNU pinentry
	URL:=http://www.gnupg.org/
endef

define Package/pinentry/description
 pinentry is a small collection of dialog programs
 that allow GnuPG to read passphrases and PIN numbers
 in a secure manner.
 There are versions for the common GTK and Qt toolkits
 as well as for the text terminal (Curses).
endef

CONFIGURE_ARGS += \
	--enable-pinentry-curses \
	--disable-pinentry-qt5

define Package/pinentry/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/pinentry-curses \
		$(1)/opt/bin/pinentry
endef

$(eval $(call BuildPackage,pinentry))
