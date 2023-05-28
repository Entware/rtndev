#
# Copyright (C) 2023 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# only build static library (neovim)

include $(TOPDIR)/rules.mk

PKG_NAME:=libtermkey
PKG_VERSION:=0.22
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://www.leonerd.org.uk/code/libtermkey
PKG_HASH:=6945bd3c4aaa83da83d80a045c5563da4edd7d0374c62c0d35aec09eb3014600

PKG_LICENSE:=MIT
PKG_LICENSE_FILES:=LICENSE

include $(INCLUDE_DIR)/package.mk

define Package/libtermkey
  SECTION:=libs
  CATEGORY:=Libraries
  TITLE:=allows easy processing of keyboard entry
  URL:=https://www.leonerd.org.uk/code/libtermkey
  PKG_MAINTAINER:=Entware team, https://entware.net
  BUILDONLY:=1
endef

define Package/libtermkey/description
  This library allows easy processing of keyboard entry from
  terminal-based programs. It handles all the necessary logic
  to recognise special keys, UTF-8 combining, and so on, with
  a simple interface.
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/opt/include
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/termkey.h $(1)/opt/include
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_BUILD_DIR)/.libs/libtermkey.a $(1)/opt/lib
endef

$(eval $(call BuildPackage,libtermkey))
