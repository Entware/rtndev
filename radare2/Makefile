#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# 5.4.0 failed to compile with following message
# ../libr/util/signal.c:19:17: error: 'SIGSTKFLT' undeclared here (not in a function); did you mean 'SIGSTKSZ'?

include $(TOPDIR)/rules.mk

PKG_NAME:=radare2
PKG_VERSION:=5.3.1
PKG_REV:=afe6d96aaf1722a9e4783a689f9f1a3a4685d612
PKG_RELEASE:=1


PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/radareorg/radare2.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=76af00ae1be02002413dcbb783f66c8557fb5c39f79036c50d01e3132f229550

PKG_BUILD_DEPENDS:=python3/host

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/meson.mk

define Package/radare2
	SECTION:=devel
	CATEGORY:=Development
	DEPENDS:=@!TARGET_armv7_2_6 +libuv
	TITLE:=reverse engineering framework
	URL:=https://www.radare.org/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/radare2/description
 UNIX-like reverse engineering framework and command-line toolset.
endef

define Package/radare2/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/bin $(1)/opt
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libr_* $(1)/opt/lib
	$(INSTALL_DIR) $(1)/opt/share/radare2
	$(CP) $(PKG_INSTALL_DIR)/opt/share/radare2/$(PKG_VERSION) \
		$(1)/opt/share/radare2
endef

$(eval $(call BuildPackage,radare2))
