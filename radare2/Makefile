# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2025 Entware
#

include $(TOPDIR)/rules.mk

PKG_NAME:=radare2
PKG_VERSION:=5.9.8
PKG_REV:=4eb49d5ad8c99eaecc8850a2f10bad407067c898
PKG_RELEASE:=1


PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/radareorg/radare2.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=8f3f6329bfa81b951db09c328748f64c1e99bb2a3f26157e3e2ae4422e760dcb

PKG_BUILD_DEPENDS:=python3/host

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/meson.mk

define Package/radare2
	SECTION:=devel
	CATEGORY:=Development
	DEPENDS:=@!TARGET_armv7_2_6 +(mips||mipsel):libatomic +libuv
	TITLE:=reverse engineering framework
	URL:=https://www.radare.org/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/radare2/description
 UNIX-like reverse engineering framework and command-line toolset.
endef

ifeq ($(or $(CONFIG_mips),$(CONFIG_mipsel)),y)
TARGET_LDFLAGS+=-latomic
endif

define Package/radare2/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/bin $(1)/opt
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libr_* $(1)/opt/lib
	$(INSTALL_DIR) $(1)/opt/share/radare2
	$(CP) $(PKG_INSTALL_DIR)/opt/share/radare2/$(PKG_VERSION) \
		$(1)/opt/share/radare2
endef

$(eval $(call BuildPackage,radare2))
