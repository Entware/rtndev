# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2026 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=inetutils
PKG_VERSION:=2.7
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=@GNU/$(PKG_NAME)
PKG_HASH:=a156be1cde3c5c0ffefc262180d9369a60484087907aa554c62787d2f40ec086

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/inetutils
	SECTION:=net
	CATEGORY:=Network
	DEPENDS:=+libreadline +libncurses
	TITLE:=GNU network utilities
	URL:=http://www.gnu.org/software/inetutils/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/inetutils/description
 Inetutils is a collection of common network programs.
endef

CONFIGURE_ARGS += \
	--with-ncurses-include-dir=$(STAGING_DIR)/opt/include \
	--with-libreadline-prefix=$(STAGING_DIR)/opt \
	--program-prefix=inetutils- \
	--libexecdir=/opt/libexec

define Package/inetutils/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/inetutils-* $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/libexec
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/libexec/inetutils-* $(1)/opt/libexec
endef

$(eval $(call BuildPackage,inetutils))
