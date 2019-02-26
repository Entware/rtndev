#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=inetutils
PKG_VERSION:=1.9.4
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=@GNU/$(PKG_NAME)
PKG_HASH:=be8f75eff936b8e41b112462db51adf689715658a1b09e0d6b05d11ec92cc616

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
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/inetutils-* $(1)/opt/bin/
	$(INSTALL_DIR) $(1)/opt/libexec
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/libexec/inetutils-* $(1)/opt/libexec/
endef

$(eval $(call BuildPackage,inetutils))
