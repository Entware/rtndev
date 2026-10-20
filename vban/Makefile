# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2025-2026 Entware

# https://github.com/Entware/Entware/issues/970

include $(TOPDIR)/rules.mk

PKG_NAME:=vban
PKG_VERSION:=2.2.0
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://codeload.github.com/quiniouben/vban/tar.gz/refs/tags/v$(PKG_VERSION)?
PKG_HASH:=fbb7e4e4e662dfdb4e08a07cfa8392e5bb09252e9b0dcfe2bbbe98fe7531778a

PKG_MAINTAINER:=Entware team, https://entware.net
PKG_LICENSE:=GPL-3.0-or-later
PKG_LICENSE_FILES:=COPYING

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/vban
  SECTION:=sound
  CATEGORY:=Sound
  TITLE:=VBAN protocol
  URL:=https://vb-audio.com/Voicemeeter/vban.htm
  DEPENDS:=+alsa-lib
endef

define Package/vban/description
  vban - Linux command-line VBAN tools.
endef

CONFIGURE_ARGS += \
	--disable-pulseaudio \
	--disable-jack

define Package/vban/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) \
		$(PKG_INSTALL_DIR)/opt/bin/vban_{emitter,receptor,sendtext} \
			$(1)/opt/bin
endef

$(eval $(call BuildPackage,vban))
