# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2006-2015 OpenWrt.org
# Copyright (C) 2020-2026 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=pinentry
PKG_VERSION:=1.3.2
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=https://gnupg.org/ftp/gcrypt/pinentry
PKG_HASH:=8e986ed88561b4da6e9efe0c54fa4ca8923035c99264df0b0464497c5fb94e9e

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
