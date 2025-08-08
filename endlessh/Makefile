# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2025 Entware

# https://github.com/Entware/Entware/issues/1016

include $(TOPDIR)/rules.mk

PKG_NAME:=endlessh
PKG_VERSION:=1.1
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://codeload.github.com/skeeto/endlessh/tar.gz/refs/tags/$(PKG_VERSION)?
PKG_HASH:=786cea9e2c8e0a37d3d4ecd984ca4a0ae0b2d6e2b8da37e3cdbb9d49ccdecbf0

PKG_MAINTAINER:=Entware team, https://entware.net
PKG_LICENSE:=Unlicense
PKG_LICENSE_FILES:=UNLICENSE

include $(INCLUDE_DIR)/package.mk

define Package/endlessh
  SECTION:=net
  CATEGORY:=Network
  TITLE:=SSH tarpit that slowly sends an endless banner
  URL:=https://github.com/skeeto/endlessh
endef

define Package/endlessh/description
  Endlessh is an SSH tarpit that very slowly sends an endless,
  random SSH banner.
endef

define Package/endlessh/conffiles
/opt/etc/endlessh.conf
endef

Build/Configure:=:

TARGET_CFLAGS += -std=c99 -Wall -Wextra

define Build/Compile
	$(TARGET_CC) $(TARGET_CFLAGS) $(TARGET_CPPFLAGS) \
		-o $(PKG_BUILD_DIR)/endlessh $(PKG_BUILD_DIR)/endlessh.c \
		$(TARGET_LDFLAGS)
endef

define Package/endlessh/install
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/endlessh $(1)/opt/sbin
	$(INSTALL_DIR) $(1)/opt/etc
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/util/smf/endlessh.conf $(1)/opt/etc
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_BIN) ./files/S99endlessh $(1)/opt/etc/init.d
endef

$(eval $(call BuildPackage,endlessh))
